#include "chlog/Input.hpp"

#include "chlog/LogHandler.hpp"

namespace chlog
{

//------------------------------------------------------------------------------
//                             PROTECTED CONSTRUCTOR
//------------------------------------------------------------------------------

Input::Input(chlog::LogHandler* log_handler, const chlog::Profile& profile)
    :
    critical(log_handler, chlog::VERBOSITY_CRITICAL, profile),
    error   (log_handler, chlog::VERBOSITY_ERROR,    profile),
    warning (log_handler, chlog::VERBOSITY_WARNING,  profile),
    notice  (log_handler, chlog::VERBOSITY_NOTICE,   profile),
    info    (log_handler, chlog::VERBOSITY_INFO,     profile),
    debug   (log_handler, chlog::VERBOSITY_DEBUG,    profile)
{
}

// //------------------------------------------------------------------------------
// //                                 STREAM BUFFER
// //------------------------------------------------------------------------------

// /*!
//  * \brief Stream buffer which will be used internal to chlog::Input.
//  */
// class Input::StreamBuffer : public std::stringbuf
// {
// public:

//     //-------------------------------CONSTRUCTOR--------------------------------

//     StreamBuffer(
//             chlog::LogHandler* log_handler,
//             chlog::Verbosity verbosity,
//             const chlog::Profile& profile)
//         :
//         m_log_handler(log_handler),
//         m_verbosity  (verbosity),
//         m_profile    (profile)
//     {
//     }

//     //-------------------------PUBLIC MEMBER FUNCTIONS--------------------------

//     virtual int sync()
//     {
//         // send to outputs
//         CHAOS_FOR_EACH(it, (m_log_handler->get_outputs()))
//         {
//             // TODO: optimise UTF8?
//             (*it)->write(m_verbosity, m_profile, str().c_str());
//         }
//         // clear
//         str("");

//         return 0;
//     }

// private:

//     //----------------------------PRIVATE ATTRIBUTES----------------------------

//     /*!
//      * \brief The log handler that owns this buffer's parent.
//      */
//     chlog::LogHandler* const m_log_handler;

//     /*!
//      * \brief The verbosity level of the input this stream is attached to.
//      */
//     const chlog::Verbosity m_verbosity;

//     /*!
//      * \brief The logging profile of the input this stream is attached to.
//      */
//     const chlog::Profile m_profile;
// };

// //------------------------------------------------------------------------------
// //                                   DESTRUCTOR
// //------------------------------------------------------------------------------

// Input::~Input()
// {
//     delete m_buffer;
// }

// //------------------------------------------------------------------------------
// //                             PROTECTED CONSTRUCTOR
// //------------------------------------------------------------------------------

// Input::Input(
//         chlog::LogHandler* log_handler,
//         chlog::Verbosity verbosity,
//         const chlog::Profile& profile)
//     :
//     std::ostream(new StreamBuffer(log_handler, verbosity, profile)),
//     m_buffer    (static_cast<StreamBuffer*>(rdbuf()))
// {
// }

} // namespace chlog
