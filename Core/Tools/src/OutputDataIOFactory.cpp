#include "OutputDataIOFactory.h"
#include "Exceptions.h"
#include "Utils.h"


/* ************************************************************************* */
// reading output data
/* ************************************************************************* */
OutputData<double > *OutputDataIOFactory::getOutputData(const std::string &file_name)
{
    return getReader(file_name)->getOutputData();
}


OutputDataIOFactory::OutputDataReader_t OutputDataIOFactory::getReader(const std::string &file_name)
{
    OutputDataReader *reader = new OutputDataReader( file_name );

    IOutputDataReadStrategy *read_strategy(0);
    if( Utils::FileSystem::GetFileMainExtension(file_name) == ".txt") {
        read_strategy = new OutputDataReadStreamV1();
    } else if ( Utils::FileSystem::GetFileMainExtension(file_name) == ".ima") {
        read_strategy = new OutputDataReadStreamIMA();
    } else {
        throw LogicErrorException("OutputDataIOFactory::getReader() -> Error. Don't know how to read file '" + file_name+std::string("'"));
    }

    if( Utils::FileSystem::isGZipped(file_name) ) {
        reader->setStrategy( new OutputDataReadStreamGZip( read_strategy ) );
    } else {
        reader->setStrategy( read_strategy );
    }

    return OutputDataReader_t(reader);
}


/* ************************************************************************* */
// writing output data
/* ************************************************************************* */
void OutputDataIOFactory::writeOutputData(const OutputData<double> &data, const std::string &file_name)
{
    return getWriter(file_name)->writeOutputData(data);
}

OutputDataIOFactory::OutputDataWriter_t OutputDataIOFactory::getWriter(const std::string &file_name)
{
    OutputDataWriter *writer = new OutputDataWriter( file_name );

    IOutputDataWriteStrategy *write_strategy(0);
    if( Utils::FileSystem::GetFileExtension(file_name) == ".ima") {
        write_strategy = new OutputDataWriteStreamIMA();
    } else {
        throw LogicErrorException("OutputDataIOFactory::getWriter() -> Error. Don't know how to write file '" + file_name+std::string("'"));
    }

    writer->setStrategy( write_strategy );

    return OutputDataWriter_t(writer);
}
