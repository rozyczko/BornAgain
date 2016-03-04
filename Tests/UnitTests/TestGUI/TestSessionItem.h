#ifndef TESTSESSIONITEM_H
#define TESTSESSIONITEM_H


#include <QtTest>
#include "ParameterizedItem.h"
#include "GUIHelpers.h"
#include "verify_throw_macro.h"



class TestSessionItem : public QObject {
    Q_OBJECT
private:
    void verify_get_item(ParameterizedItem *item, const QString &tag, QVector<ParameterizedItem*> list);
private slots:
    void test_constructor();
    void test_tags();
};


inline void TestSessionItem::verify_get_item(ParameterizedItem *item, const QString &tag, QVector<ParameterizedItem *> list)
{
    if (list.size() > 0)
        QVERIFY(item->getItem(tag) == list[0]);
    else
        QVERIFY(item->getItem(tag) == nullptr);
    auto items = item->getItems(tag);
    QVERIFY(items.size() == list.size());
    QVERIFY(items == list);
    QVERIFY(item->getItem(tag, -1) == nullptr);
    QVERIFY(item->getItem(tag, list.size()) == nullptr);
    for (int i = 0; i < list.size(); i++) {
        QVERIFY(item->getItem(tag, i) == list[i]);
    }
}

inline void TestSessionItem::test_constructor()
{
    const QString modeltype = "This is the model type";
    ParameterizedItem *item = new ParameterizedItem(modeltype);
    QVERIFY(item->modelType() == modeltype);
    QVERIFY(item->model() == nullptr);
    QVERIFY(item->parent() == nullptr);
    // TODO add some more tests for children, roles, tags ...
}

inline void TestSessionItem::test_tags()
{
    const QString modeltype = "This is the model type";
    const QString tag1 = "TAG1";
    const QString tag2 = "TAG2";
    const QString tag3 = "TAG3";
    const QString tag4 = "TAG4";
    ParameterizedItem *item = new ParameterizedItem(modeltype);
    QVector<ParameterizedItem*> items;
    for (int i = 0; i < 10; i++)
        items.append(new ParameterizedItem(modeltype));

    // before using a tag, it must be registered
    QVERIFY(item->registerTag(tag1));

    // register twice returns false
    QVERIFY(item->registerTag(tag1) == false);

    // register empty string returns false
    QVERIFY(item->registerTag("") == false);

    // now we insert one element at the beginning
    QVERIFY(item->insertItemToTag(0, items[0], tag1));

    // insertion out of range is forbidden
    QVERIFY(item->insertItemToTag(-1, items[0], tag1) == false);
    QVERIFY(item->insertItemToTag(2, items[0], tag1) == false);

    // double insertion is forbidden
    QVERIFY(item->insertItemToTag(0, items[0], tag1) == false);

    // we try to access tagged items
    verify_get_item(item, tag1, items.mid(0, 1));

    // nullptr is allowed
    QVERIFY(item->insertItemToTag(1, nullptr, tag1));
    auto vecWithNullptr = items.mid(0,1);
    vecWithNullptr.append(nullptr);
    verify_get_item(item, tag1, vecWithNullptr);

    // LIMITS
    // register tag with limit 0 - 1
    QVERIFY(item->registerTag(tag2, 0, 1));

    QVERIFY(item->insertItemToTag(0, items[1], tag2));
    verify_get_item(item, tag2, items.mid(1,1));
    QVERIFY(item->insertItemToTag(1, items[1], tag2) == false);

    // register tag with limit 0 - 3 (using item 2 - 5)
    QVERIFY(item->registerTag(tag3, 0, 4));

    // add four items
    for (int i = 0; i < 4; i++) {
        QVERIFY(item->insertItemToTag(i, items[2 + i], tag3));
        verify_get_item(item, tag3, items.mid(2, i+1));
    }

    // the fifth should fail
    QVERIFY(item->insertItemToTag(0, items[6], tag3) == false);

    // items should be unchanged
    verify_get_item(item, tag3, items.mid(2, 4));

    // register tag with limit 4 - 4 add items to fill up limit
    QVERIFY(item->registerTag(tag4, 4, 4));

    // add four items
    for (int i = 0; i < 4; i++) {
        QVERIFY(item->insertItemToTag(i, items[6 + i], tag4));
        verify_get_item(item, tag4, items.mid(6, i+1));
    }
    QVERIFY(item->insertItemToTag(0, items[6], tag4) == false);

    // REMOVAL

    // tag4 can not be removed
    ParameterizedItem *last = item->takeItem(3, tag4);
    QVERIFY(last == nullptr);
    verify_get_item(item, tag4, items.mid(6, 4));

    // remove all from tag3, checking access of tag4
    for (int i = 0; i < 4; i++) {
        last = item->takeItem(3-i, tag3);
        QVERIFY(last == items[5-i]);
        verify_get_item(item, tag3, items.mid(2,3-i));
        verify_get_item(item, tag4, items.mid(6,4));
    }
}

//inline void TestParameterizedItem::test_registerProperty()
//{
//    ParameterizedItem item;
//    QString property_name("MyProperty");
//    double value(1.0);
////    QSignalSpy spy(&item, SIGNAL(propertyChanged(QString)));

//    // access non-existing property
//    QCOMPARE(false, item.isRegisteredProperty(property_name));
//    QVERIFY_THROW(item.getRegisteredProperty(property_name), GUIHelpers::Error);
//    QVERIFY_THROW(item.setRegisteredProperty(property_name, value), GUIHelpers::Error);

//    // registering new property
//    item.registerProperty(property_name, value);
//    QCOMPARE(true, item.isRegisteredProperty(property_name));
////    QCOMPARE(spy.count(), 1);
////    QList<QVariant> arguments = spy.takeFirst();
////    QCOMPARE(arguments.size(), 1);
////    QCOMPARE(arguments.at(0).toString(), property_name);
//    QCOMPARE(item.getRegisteredProperty(property_name).toDouble(), value);
////    QCOMPARE(spy.count(), 0);

//    // setting property value
//    double new_value(2.0);
//    item.setRegisteredProperty(property_name, new_value);
////    QCOMPARE(spy.count(), 1);
////    arguments = spy.takeFirst();
////    QCOMPARE(arguments.size(), 1);
////    QCOMPARE(arguments.at(0).toString(), property_name);
//    QCOMPARE(item.getRegisteredProperty(property_name).toDouble(), new_value);

//    // setting property value to wrong QVariant
//    QVERIFY_THROW(item.setRegisteredProperty(property_name, QString("aaa")), GUIHelpers::Error);

//    // attempt to register already existing property
//    QVERIFY_THROW(item.registerProperty(property_name, 1.0), GUIHelpers::Error);

//    // remove registered property
//    item.removeRegisteredProperty(property_name);
////    QCOMPARE(spy.count(), 1);
////    arguments = spy.takeFirst();
////    QCOMPARE(arguments.size(), 1);
////    QCOMPARE(arguments.at(0).toString(), property_name);
//    QVERIFY_THROW(item.getRegisteredProperty(property_name), GUIHelpers::Error);
//}

//inline void TestParameterizedItem::test_SelectableGroupProperty()
//{
////    ParameterizedItem item;
////    QCOMPARE(item.getSubItems().size(), 0);
//}


#endif
