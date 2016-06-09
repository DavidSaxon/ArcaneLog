/*!
 * \file
 * \author David Saxon
 */
#ifndef CHAOSCORE_IO_SYS_FILEWRITER_HPP_
#define CHAOSCORE_IO_SYS_FILEWRITER_HPP_

#include "chaoscore/io/sys/FileHandle.hpp"

class ofstream;

namespace chaos
{
namespace io
{
namespace sys
{


/*!
 * \brief Used for writing to a file on disk.
 */
class FileWriter : public chaos::io::sys::FileHandle
{
private:

    CHAOS_DISALLOW_COPY_AND_ASSIGN(FileWriter);

public:

    //--------------------------------------------------------------------------
    //                                 ENUMERATOR
    //--------------------------------------------------------------------------

    /*!
     * \brief The possible modes the FileWriter can be opened in.
     */
    enum OpenMode
    {
        /// Any existing data in the file will be removed and the FileWriter
        /// will begin from the start of the file.
        OPEN_TRUNCATE = 0,
        /// Existing data will be retained in the file and the FileWriter will
        /// begin from the end of the existing data.
        OPEN_APPEND
    };

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /*!
     * \brief Default constructor.
     *
     * Creates a new unopened FileWriter with no file path yet defined.
     *
     * \param open_mode Defines the mode which the file should be opened with.
     * \param encoding Defines the encoding that data will be written to the
     *                 file in. If chaos::io::sys::FileHandle::ENCODING_DETECT
     *                 the writer will use
     *                 chaos::io::sys::FileHandle::ENCODING_RAW.
     * \param newline The newline symbol that will be used to write lines to the
     *                file.
     */
    FileWriter(
            OpenMode open_mode = OPEN_TRUNCATE,
            Encoding encoding = ENCODING_RAW,
            Newline newline   = NEWLINE_UNIX);

    /*!
     * \brief Path constructor.
     *
     * Creates a new FileWriter opened to the given path/
     *
     * \param The path to the file to write to.
     * \param open_mode Defines the mode which the file should be opened with.
     * \param encoding Defines the encoding that data will be written to the
     *                 file in. If chaos::io::sys::FileHandle::ENCODING_DETECT
     *                 the writer will use
     *                 chaos::io::sys::FileHandle::ENCODING_RAW.
     * \param newline The newline symbol that will be used to write lines to the
     *                file.
     *
     * \throws chaos::ex::InvalidPathError If the path cannot be opened.
     */
    FileWriter(
            const chaos::io::sys::Path& path,
            OpenMode open_mode = OPEN_TRUNCATE,
            Encoding encoding = ENCODING_RAW,
            Newline newline   = NEWLINE_UNIX);

    /*!
     * \brief Move constructor.
     *
     * \param other The FileWriter to move resources from.
     */
    FileWriter(FileWriter&& other);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~FileWriter();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief Opens this FileWriter to the internal path.
     *
     * \note If a encoding other than chaos::io::sys::FileHandle::ENCODING_RAW
     *       is being used and the open mode is
     *       chaos::io::sys::FileWriter::OPEN_TRUNCATE, opening will cause the
     *       relevant Unicode BOM to be written to the start of the file.
     *
     * \throws chaos::ex::StateError If this FileWriter is already open.
     * \throws chaos::ex::InvalidPathError If the path cannot be opened.
     */
    virtual void open();

    // override to avoid C++ function hiding
    virtual void open(const chaos::io::sys::Path& path);

    /*!
     * \brief Closes this FileWriter.
     */
    virtual void close();

    /*!
     * \brief Returns the size of the file being written in bytes.
     *
     * \throws chaos::ex::StateError If the FileWriter is not open.
     */
    virtual chaos::int64 get_size() const;

    /*!
     * \brief Returns the index of the byte the file position indicator is
     *        currently at.
     *
     * \throws chaos::ex::StateError If the FileWriter is not open.
     */
    virtual chaos::int64 tell() const;

    /*!
     * \brief Sets the file position indicator to the given byte index.
     *
     * \throws chaos::ex::StateError If the FileWriter is not open.
     * \throws chaos::ex::IndexOutOfBoundsError If the given byte index is
     *                                          greater than the number of bytes
     *                                          in the file or is less than 0.
     */
    virtual void seek(chaos::int64 index);

    /*!
     * \brief Writes the given data array to the file.
     *
     * This function writes the raw bytes of the input data to the file,
     * therefore it assumes the input data isin  the correct encoding. Any
     * newline characters in the data are not converted to this FileWriter's
     * newline type and are left as is.
     *
     * \param data The byte array to write to the file.
     * \param length The number of bytes in the provided data.
     *
     * \throws chaos::ex::StateError If this FileWriter is not open.
     */
    void write(const char* data, std::size_t length);

    /*!
     * \brief Writes the given chaos::str::UTF8String to the file.
     *
     * The contents of the data will be converted to this FileWriter's
     * respective encoding. Any newline symbols within the data are not
     * converted to this FileWriter's newline type and are left as is.
     *
     * \param data The string to write to the file.
     *
     * \throws chaos::ex::StateError If this FileWriter is not open.
     */
    void write(const chaos::str::UTF8String& data);

    /*!
     * \brief Writes the given data to the file followed by a newline symbol.
     *
     * This function writes the raw bytes of the input data to the file,
     * therefore it assumes the input data is in the correct encoding. However
     * the newline character appended to the data will match the newline type
     * being used by this FileWriter and be in the appropriate encoding.
     * Any newline symbols within the input data will not be converted to match
     * the FileWriter's newline type.
     *
     * \param data The byte array to write to the file.
     * \param length The number of bytes in the provided data.
     *
     * \throws chaos::ex::StateError If this FileWriter is not open.
     */
    void write_line(const char* data, std::size_t length);

    /*!
     * \brief Writes the given chaos::str::UTF8String to the file followed by a
     *        newline symbol.
     *
     * The contents of the data will be converted to this FileWriter's
     * respective encoding. A newline character that matches the writer's
     * encoding and newline type will be appended to the file after the data has
     * been written. Any newline symbols within the data will not be converted
     * to match the FileWriter's newline type.
     *
     * \param data The string to write to the file.
     *
     * \throws chaos::ex::StateError If this FileWriter is not open.
     */
    void write_line(const chaos::str::UTF8String& data);

private:

    //--------------------------------------------------------------------------
    //                             PRIVATE ATTRIBUTES
    //--------------------------------------------------------------------------

    /*!
     * \brief The mode the FileWriter should be opened with.
     */
    OpenMode m_open_mode;

    /*!
     * \brief The output stream used to write to the file.
     */
    std::ofstream* m_stream;
};

} // namespace sys
} // namespace io
} // namespace chaos

#endif