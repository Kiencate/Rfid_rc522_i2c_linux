#ifndef DBUSADAPTOR_H
#define DBUSADAPTOR_H


#include <QtDBus/QDBusAbstractAdaptor>
#include <QtDBus/QDBusObjectPath>
#include <QDebug>
#include <QtDBus/QDBusInterface>
#include <QString>
#include <QTimer>

class MyQDusAdaptor: public QDBusAbstractAdaptor
{

    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.bluez.Agent1")
    Q_CLASSINFO("D-Bus Introspection", ""
                                                                         "  <interface name=\"org.bluez.Agent1\">\n"
                                                                         "    <method name=\"RequestConfirmation\">\n"
                                                                         "      <arg direction=\"in\" type=\"ou\"/>\n"
                                                                         "      <arg direction=\"out\" type=\"\"/>\n"
                                                                         "    </method>\n"
                                                                         "  </interface>\n"
                                                                         "")

public:
        MyQDusAdaptor(QObject *parent);
        virtual ~MyQDusAdaptor();
signals:
        void Connect_success();
        /*
        * emit to backend when bluetooth connect success
        */
public: // PROPERTIES
public Q_SLOTS: // METHODS
        void RequestConfirmation(const QDBusObjectPath &in0, quint32 passkey );
        /*
        * override the method of interface org.bluez.Agent1
        */
private:
        QDBusObjectPath device;
        /*
        * object for device android in bluetooth manager
        */
        QDBusInterface *deviceprop;
        /*
        * property of device android in bluetooth manager
        */
        QTimer *check_connect_timer;
};

#endif // DBUSADAPTOR_H
