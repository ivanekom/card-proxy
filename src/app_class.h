#ifndef _CARD_PROXY__APP_H_
#define _CARD_PROXY__APP_H_

#include <memory>
#include <string>
#include <fstream>
#include <util/nlogger.h>
#include <util/singleton.h>
#include <orm/data_object.h>

class App: public Yb::ILogger
{
    std::auto_ptr<std::ofstream> file_stream_;
    std::auto_ptr<Yb::LogAppender> appender_;
    Yb::ILogger::Ptr log_;
    std::auto_ptr<Yb::Engine> engine_;

    void init_log(const std::string &log_name);
    void init_engine(const std::string &db_name);
public:
    App() {}
    void init(const std::string &log_name = "log.txt",
            const std::string &db_name = "db");
    virtual ~App();
    Yb::Engine *get_engine();
    std::auto_ptr<Yb::Session> new_session();
    Yb::ILogger::Ptr new_logger(const std::string &name);
    void log(int level, const std::string &msg);
    const std::string get_name() const;
};

typedef Yb::SingletonHolder<App> theApp;

#endif // _CARD_PROXY__APP_H_
// vim:ts=4:sts=4:sw=4:et:
