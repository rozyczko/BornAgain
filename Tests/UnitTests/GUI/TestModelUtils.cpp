#include "google_test.h"
#include "ModelUtils.h"
#include "SessionModel.h"
#include "item_constants.h"
#include "VectorItem.h"
#include "LayerItem.h"
#include <QVector>

class TestModelUtils : public ::testing::Test
{
public:
    ~TestModelUtils();

    //! Returns true if model contains given item using iterate_if procedure.
    bool modelContainsItem(SessionModel* model, SessionItem* selectedItem)
    {
        bool result = false;
        ModelUtils::iterate_if(QModelIndex(), model, [&](const QModelIndex& index) -> bool {
            SessionItem* item = model->itemForIndex(index);
            if (item == selectedItem)
                result = true;
            return item->isVisible();
        });
        return result;
    }
};

TestModelUtils::~TestModelUtils() = default;

//! Testing top item names.

TEST_F(TestModelUtils, test_topItemNames)
{
    SessionModel model("TestModel");

    // testing empty list
    EXPECT_TRUE(ModelUtils::topItemNames(&model).isEmpty());

    // inserting three top items
    auto item = model.insertNewItem(Constants::MultiLayerType);
    item->setItemName("name1");
    item = model.insertNewItem(Constants::LayerType);
    item = model.insertNewItem(Constants::MultiLayerType);
    item->setItemName("name2");

    // checking names of items of certain type
    ASSERT_EQ(ModelUtils::topItemNames(&model, Constants::MultiLayerType).size(), 2);
    EXPECT_EQ(ModelUtils::topItemNames(&model, Constants::MultiLayerType).at(0), QString("name1"));
    EXPECT_EQ(ModelUtils::topItemNames(&model, Constants::MultiLayerType).at(1), QString("name2"));

    // checking names of all top items
    QStringList expected = {"name1", Constants::LayerType, "name2"};
    EXPECT_EQ(ModelUtils::topItemNames(&model), expected);
}


//! Testing iteration over empty model.

TEST_F(TestModelUtils, test_emptyModel)
{
    SessionModel model("TestModel");

    QVector<QModelIndex> indices;

    ModelUtils::iterate(QModelIndex(), &model,
                        [&](const QModelIndex& index) { indices.push_back(index); });

    EXPECT_EQ(indices.size(), 0);
}

//! Testing iteration over the model with one VectorItem inserted.

TEST_F(TestModelUtils, test_vectorItem)
{
    SessionModel model("TestModel");
    SessionItem* vectorItem = model.insertNewItem(Constants::VectorType);

    QVector<QModelIndex> indices;

    // checking indices visited during iteration
    ModelUtils::iterate(QModelIndex(), &model,
                        [&](const QModelIndex& index) { indices.push_back(index); });
    EXPECT_EQ(indices.size(), 8); // (VectorItem, P_X, P_Y, P_Z) x (row, col)

    indices.clear();
    ModelUtils::iterate(QModelIndex(), &model, [&](const QModelIndex& index) {
        if (index.column() == 0)
            indices.push_back(index);
    });

    // checking SessionItems visited during the iteration
    EXPECT_EQ(indices.size(), 4); // (VectorItem, P_X, P_Y, P_Z) x (row, col)
    EXPECT_EQ(model.itemForIndex(indices.front()), vectorItem);
    EXPECT_EQ(model.itemForIndex(indices.back()), vectorItem->getItem(VectorItem::P_Z));
}

//! Tests iteration when some children is invisible.

TEST_F(TestModelUtils, test_iterateIf)
{
    SessionModel model("TestModel");
    SessionItem* multilayer = model.insertNewItem(Constants::MultiLayerType);
    SessionItem* layer = model.insertNewItem(Constants::LayerType, model.indexOfItem(multilayer));
    SessionItem* thicknessItem = layer->getItem(LayerItem::P_THICKNESS);

    layer->setVisible(true);
    EXPECT_TRUE(modelContainsItem(&model, layer));
    EXPECT_TRUE(modelContainsItem(&model, thicknessItem));

    // Setting layer invisible will hide its children from iteration.
    // Layer itself still will be visible.
    layer->setVisible(false);

    layer->setVisible(false);
    EXPECT_TRUE(modelContainsItem(&model, layer));
    EXPECT_FALSE(modelContainsItem(&model, thicknessItem));
}
