#include "chlog/Input.hpp"

#include <sstream>

#include "chlog/AbstractOutput.hpp"
#include "chlog/LogHandler.hpp"

namespace chlog
{

//------------------------------------------------------------------------------
//                                 STREAM BUFFER
//------------------------------------------------------------------------------

/*!
 * \brief Stream buffer which will be used internal to chlog::Input.
 */
class Input::StreamBuffer : public std::stringbuf
{
public:

    //-------------------------------CONSTRUCTOR--------------------------------

    StreamBuffer(chlog::LogHandler* log_handler)
        :
        m_log_handler(log_handler)
    {
    }

    //-------------------------PUBLIC MEMBER FUNCTIONS--------------------------

    virtual int sync()
    {
        // TODO: clear and do nothing if the stream is disabled

        // TODO: apply prefix

        // TODO apply post fix

        // TODO: send parent Logger

        // std::cout << str();
        // str("");
        // std::cout.flush();

        // send to outputs
        CHAOS_FOR_EACH(it, (m_log_handler->get_outputs()))
        {
            // TODO: verbosity
            // TODO: optimise UTF8?
            (*it)->write(1, str().c_str());
        }
        // clear
        str("");

        return 0;
    }

private:

    //----------------------------PRIVATE ATTRIBUTES----------------------------

    /*!
     * \brief The log handler that owns this buffer's parent.
     */
    chlog::LogHandler* m_log_handler;
};

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Input::~Input()
{
    delete m_buffer;
}

//------------------------------------------------------------------------------
//                             PROTECTED CONSTRUCTOR
//------------------------------------------------------------------------------

Input::Input(
        chlog::LogHandler* log_handler,
        chaos::uint32 verbosity)
    :
    std::ostream(new StreamBuffer(log_handler)),
    m_buffer    (static_cast<StreamBuffer*>(rdbuf())),
    m_verbosity (verbosity)
{
}

} // namespace chlog
