/****************************************************************************
** Meta object code from reading C++ file 'NewTcpClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../NewTcpClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NewTcpClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_network_st__NewTcpClient_t {
    QByteArrayData data[15];
    char stringdata[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_network_st__NewTcpClient_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_network_st__NewTcpClient_t qt_meta_stringdata_network_st__NewTcpClient = {
    {
QT_MOC_LITERAL(0, 0, 24), // "network_st::NewTcpClient"
QT_MOC_LITERAL(1, 25, 33), // "Signal_UpdateUITcpReceivedMes..."
QT_MOC_LITERAL(2, 59, 0), // ""
QT_MOC_LITERAL(3, 60, 12), // "MessageUnit*"
QT_MOC_LITERAL(4, 73, 12), // "_messageUnit"
QT_MOC_LITERAL(5, 86, 25), // "Slot_BindNewTcpConnection"
QT_MOC_LITERAL(6, 112, 14), // "Slot_Connected"
QT_MOC_LITERAL(7, 127, 17), // "Slot_DisplayError"
QT_MOC_LITERAL(8, 145, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(9, 174, 5), // "error"
QT_MOC_LITERAL(10, 180, 17), // "Slot_Disconnected"
QT_MOC_LITERAL(11, 198, 21), // "Slot_GetServerAddress"
QT_MOC_LITERAL(12, 220, 17), // "Slot_StateChanged"
QT_MOC_LITERAL(13, 238, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(14, 267, 12) // "_socketState"

    },
    "network_st::NewTcpClient\0"
    "Signal_UpdateUITcpReceivedMessage\0\0"
    "MessageUnit*\0_messageUnit\0"
    "Slot_BindNewTcpConnection\0Slot_Connected\0"
    "Slot_DisplayError\0QAbstractSocket::SocketError\0"
    "error\0Slot_Disconnected\0Slot_GetServerAddress\0"
    "Slot_StateChanged\0QAbstractSocket::SocketState\0"
    "_socketState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_network_st__NewTcpClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    1,   54,    2, 0x0a /* Public */,
      10,    0,   57,    2, 0x0a /* Public */,
      11,    0,   58,    2, 0x0a /* Public */,
      12,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void network_st::NewTcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewTcpClient *_t = static_cast<NewTcpClient *>(_o);
        switch (_id) {
        case 0: _t->Signal_UpdateUITcpReceivedMessage((*reinterpret_cast< MessageUnit*(*)>(_a[1]))); break;
        case 1: _t->Slot_BindNewTcpConnection(); break;
        case 2: _t->Slot_Connected(); break;
        case 3: _t->Slot_DisplayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->Slot_Disconnected(); break;
        case 5: _t->Slot_GetServerAddress(); break;
        case 6: _t->Slot_StateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NewTcpClient::*_t)(MessageUnit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewTcpClient::Signal_UpdateUITcpReceivedMessage)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject network_st::NewTcpClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_network_st__NewTcpClient.data,
      qt_meta_data_network_st__NewTcpClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *network_st::NewTcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *network_st::NewTcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_network_st__NewTcpClient.stringdata))
        return static_cast<void*>(const_cast< NewTcpClient*>(this));
    return QObject::qt_metacast(_clname);
}

int network_st::NewTcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void network_st::NewTcpClient::Signal_UpdateUITcpReceivedMessage(MessageUnit * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
