/****************************************************************************
** Meta object code from reading C++ file 'UdpReceiveThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UdpReceiveThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UdpReceiveThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_network_st__UdpReceiveThread_t {
    QByteArrayData data[9];
    char stringdata[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_network_st__UdpReceiveThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_network_st__UdpReceiveThread_t qt_meta_stringdata_network_st__UdpReceiveThread = {
    {
QT_MOC_LITERAL(0, 0, 28), // "network_st::UdpReceiveThread"
QT_MOC_LITERAL(1, 29, 25), // "Signal_AddReceivedMessage"
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 8), // "_message"
QT_MOC_LITERAL(4, 65, 27), // "Signal_BindNewTcpConnection"
QT_MOC_LITERAL(5, 93, 23), // "Signal_GetServerAddress"
QT_MOC_LITERAL(6, 117, 28), // "Signal_DisconnectTcpFromHost"
QT_MOC_LITERAL(7, 146, 3), // "_ip"
QT_MOC_LITERAL(8, 150, 20) // "ReadPendingDatagrams"

    },
    "network_st::UdpReceiveThread\0"
    "Signal_AddReceivedMessage\0\0_message\0"
    "Signal_BindNewTcpConnection\0"
    "Signal_GetServerAddress\0"
    "Signal_DisconnectTcpFromHost\0_ip\0"
    "ReadPendingDatagrams"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_network_st__UdpReceiveThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,
       5,    0,   43,    2, 0x06 /* Public */,
       6,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void network_st::UdpReceiveThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UdpReceiveThread *_t = static_cast<UdpReceiveThread *>(_o);
        switch (_id) {
        case 0: _t->Signal_AddReceivedMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->Signal_BindNewTcpConnection(); break;
        case 2: _t->Signal_GetServerAddress(); break;
        case 3: _t->Signal_DisconnectTcpFromHost((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->ReadPendingDatagrams(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UdpReceiveThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpReceiveThread::Signal_AddReceivedMessage)) {
                *result = 0;
            }
        }
        {
            typedef void (UdpReceiveThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpReceiveThread::Signal_BindNewTcpConnection)) {
                *result = 1;
            }
        }
        {
            typedef void (UdpReceiveThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpReceiveThread::Signal_GetServerAddress)) {
                *result = 2;
            }
        }
        {
            typedef void (UdpReceiveThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpReceiveThread::Signal_DisconnectTcpFromHost)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject network_st::UdpReceiveThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_network_st__UdpReceiveThread.data,
      qt_meta_data_network_st__UdpReceiveThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *network_st::UdpReceiveThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *network_st::UdpReceiveThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_network_st__UdpReceiveThread.stringdata))
        return static_cast<void*>(const_cast< UdpReceiveThread*>(this));
    return QThread::qt_metacast(_clname);
}

int network_st::UdpReceiveThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void network_st::UdpReceiveThread::Signal_AddReceivedMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void network_st::UdpReceiveThread::Signal_BindNewTcpConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void network_st::UdpReceiveThread::Signal_GetServerAddress()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void network_st::UdpReceiveThread::Signal_DisconnectTcpFromHost(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
