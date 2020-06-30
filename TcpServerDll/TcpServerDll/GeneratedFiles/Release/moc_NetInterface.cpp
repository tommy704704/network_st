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
#include <QtCore/QList>
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
struct qt_meta_stringdata_network_server_st__NetInterface_t {
    QByteArrayData data[14];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_network_server_st__NetInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_network_server_st__NetInterface_t qt_meta_stringdata_network_server_st__NetInterface = {
    {
QT_MOC_LITERAL(0, 0, 31), // "network_server_st::NetInterface"
QT_MOC_LITERAL(1, 32, 22), // "Signal_ReceivedMessage"
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 12), // "MessageUnit*"
QT_MOC_LITERAL(4, 69, 12), // "_messageUnit"
QT_MOC_LITERAL(5, 82, 26), // "Signal_UpdateUIReplyTcpMsg"
QT_MOC_LITERAL(6, 109, 24), // "Signal_UpdateAddressList"
QT_MOC_LITERAL(7, 134, 7), // "Client*"
QT_MOC_LITERAL(8, 142, 7), // "_client"
QT_MOC_LITERAL(9, 150, 31), // "Signal_UpdateOfflineAddressList"
QT_MOC_LITERAL(10, 182, 15), // "QList<Client*>*"
QT_MOC_LITERAL(11, 198, 8), // "_clients"
QT_MOC_LITERAL(12, 207, 20), // "Slot_ReceivedMessage"
QT_MOC_LITERAL(13, 228, 24) // "Slot_UpdateOfflineSocket"

    },
    "network_server_st::NetInterface\0"
    "Signal_ReceivedMessage\0\0MessageUnit*\0"
    "_messageUnit\0Signal_UpdateUIReplyTcpMsg\0"
    "Signal_UpdateAddressList\0Client*\0"
    "_client\0Signal_UpdateOfflineAddressList\0"
    "QList<Client*>*\0_clients\0Slot_ReceivedMessage\0"
    "Slot_UpdateOfflineSocket"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_network_server_st__NetInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,
       9,    1,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   56,    2, 0x08 /* Private */,
      13,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void network_server_st::NetInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetInterface *_t = static_cast<NetInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Signal_ReceivedMessage((*reinterpret_cast< MessageUnit*(*)>(_a[1]))); break;
        case 1: _t->Signal_UpdateUIReplyTcpMsg((*reinterpret_cast< MessageUnit*(*)>(_a[1]))); break;
        case 2: _t->Signal_UpdateAddressList((*reinterpret_cast< Client*(*)>(_a[1]))); break;
        case 3: _t->Signal_UpdateOfflineAddressList((*reinterpret_cast< QList<Client*>*(*)>(_a[1]))); break;
        case 4: _t->Slot_ReceivedMessage((*reinterpret_cast< MessageUnit*(*)>(_a[1]))); break;
        case 5: _t->Slot_UpdateOfflineSocket((*reinterpret_cast< QList<Client*>*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (NetInterface::*_t)(MessageUnit * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetInterface::Signal_ReceivedMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NetInterface::*_t)(MessageUnit * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetInterface::Signal_UpdateUIReplyTcpMsg)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NetInterface::*_t)(Client * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetInterface::Signal_UpdateAddressList)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (NetInterface::*_t)(QList<Client*> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetInterface::Signal_UpdateOfflineAddressList)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject network_server_st::NetInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_network_server_st__NetInterface.data,
      qt_meta_data_network_server_st__NetInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *network_server_st::NetInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *network_server_st::NetInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_network_server_st__NetInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int network_server_st::NetInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void network_server_st::NetInterface::Signal_ReceivedMessage(MessageUnit * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void network_server_st::NetInterface::Signal_UpdateUIReplyTcpMsg(MessageUnit * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void network_server_st::NetInterface::Signal_UpdateAddressList(Client * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void network_server_st::NetInterface::Signal_UpdateOfflineAddressList(QList<Client*> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
