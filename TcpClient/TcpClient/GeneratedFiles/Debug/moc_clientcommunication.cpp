/****************************************************************************
** Meta object code from reading C++ file 'clientcommunication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clientcommunication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientcommunication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_network_st__ClientCommunication_t {
    QByteArrayData data[8];
    char stringdata[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_network_st__ClientCommunication_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_network_st__ClientCommunication_t qt_meta_stringdata_network_st__ClientCommunication = {
    {
QT_MOC_LITERAL(0, 0, 31), // "network_st::ClientCommunication"
QT_MOC_LITERAL(1, 32, 23), // "Slot_AddReceivedMessage"
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 8), // "_message"
QT_MOC_LITERAL(4, 66, 31), // "Slot_UpdateUITcpReceivedMessage"
QT_MOC_LITERAL(5, 98, 12), // "MessageUnit*"
QT_MOC_LITERAL(6, 111, 12), // "_messageUnit"
QT_MOC_LITERAL(7, 124, 28) // "Slot_UpdateUITcpReplyMessage"

    },
    "network_st::ClientCommunication\0"
    "Slot_AddReceivedMessage\0\0_message\0"
    "Slot_UpdateUITcpReceivedMessage\0"
    "MessageUnit*\0_messageUnit\0"
    "Slot_UpdateUITcpReplyMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_network_st__ClientCommunication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       7,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void network_st::ClientCommunication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientCommunication *_t = static_cast<ClientCommunication *>(_o);
        switch (_id) {
        case 0: _t->Slot_AddReceivedMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->Slot_UpdateUITcpReceivedMessage((*reinterpret_cast< MessageUnit*(*)>(_a[1]))); break;
        case 2: _t->Slot_UpdateUITcpReplyMessage((*reinterpret_cast< MessageUnit*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject network_st::ClientCommunication::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_network_st__ClientCommunication.data,
      qt_meta_data_network_st__ClientCommunication,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *network_st::ClientCommunication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *network_st::ClientCommunication::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_network_st__ClientCommunication.stringdata))
        return static_cast<void*>(const_cast< ClientCommunication*>(this));
    return QWidget::qt_metacast(_clname);
}

int network_st::ClientCommunication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
