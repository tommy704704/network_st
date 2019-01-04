/****************************************************************************
** Meta object code from reading C++ file 'NetInterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../NetInterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NetInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_network_st__NetInterface_t {
    QByteArrayData data[12];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_network_st__NetInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_network_st__NetInterface_t qt_meta_stringdata_network_st__NetInterface = {
    {
QT_MOC_LITERAL(0, 0, 24), // "network_st::NetInterface"
QT_MOC_LITERAL(1, 25, 30), // "Signal_UpdateUITcpReplyMessage"
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 12), // "MessageUnit*"
QT_MOC_LITERAL(4, 70, 12), // "_messageUnit"
QT_MOC_LITERAL(5, 83, 33), // "Signal_UpdateUITcpReceivedMes..."
QT_MOC_LITERAL(6, 117, 23), // "Signal_GetServerAddress"
QT_MOC_LITERAL(7, 141, 25), // "Signal_AddReceivedMessage"
QT_MOC_LITERAL(8, 167, 8), // "_message"
QT_MOC_LITERAL(9, 176, 27), // "Signal_BindNewTcpConnection"
QT_MOC_LITERAL(10, 204, 39), // "Slot_RemoveSendedTcpSocketFro..."
QT_MOC_LITERAL(11, 244, 3) // "_ip"

    },
    "network_st::NetInterface\0"
    "Signal_UpdateUITcpReplyMessage\0\0"
    "MessageUnit*\0_messageUnit\0"
    "Signal_UpdateUITcpReceivedMessage\0"
    "Signal_GetServerAddress\0"
    "Signal_AddReceivedMessage\0_message\0"
    "Signal_BindNewTcpConnection\0"
    "Slot_RemoveSendedTcpSocketFromConnected\0"
    "_ip"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_network_st__NetInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,
       6,    0,   50,    2, 0x06 /* Public */,
       7,    1,   51,    2, 0x06 /* Public */,
       9,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void network_st::NetInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetInterface *_t = static_cast<NetInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Signal_UpdateUITcpReplyMessage((*reinterpret_cast< MessageUnit*(*)>(_a[1]))); break;
        case 1: _t->Signal_UpdateUITcpReceivedMessage((*reinterpret_cast< MessageUnit*(*)>(_a[1]))); break;
        case 2: _t->Signal_GetServerAddress(); break;
        case 3: _t->Signal_AddReceivedMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->Signal_BindNewTcpConnection(); break;
        case 5: _t->Slot_RemoveSendedTcpSocketFromConnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (NetInterface::*_t)(MessageUnit * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetInterface::Signal_UpdateUITcpReplyMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NetInterface::*_t)(MessageUnit * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetInterface::Signal_UpdateUITcpReceivedMessage)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NetInterface::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetInterface::Signal_GetServerAddress)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (NetInterface::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetInterface::Signal_AddReceivedMessage)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (NetInterface::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetInterface::Signal_BindNewTcpConnection)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject network_st::NetInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_network_st__NetInterface.data,
      qt_meta_data_network_st__NetInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *network_st::NetInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *network_st::NetInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_network_st__NetInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int network_st::NetInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void network_st::NetInterface::Signal_UpdateUITcpReplyMessage(MessageUnit * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void network_st::NetInterface::Signal_UpdateUITcpReceivedMessage(MessageUnit * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void network_st::NetInterface::Signal_GetServerAddress()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void network_st::NetInterface::Signal_AddReceivedMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void network_st::NetInterface::Signal_BindNewTcpConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
