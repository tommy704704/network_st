/****************************************************************************
** Meta object code from reading C++ file 'servercommunication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../servercommunication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'servercommunication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_network_st__ServerCommunication_t {
    QByteArrayData data[26];
    char stringdata0[402];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_network_st__ServerCommunication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_network_st__ServerCommunication_t qt_meta_stringdata_network_st__ServerCommunication = {
    {
QT_MOC_LITERAL(0, 0, 31), // "network_st::ServerCommunication"
QT_MOC_LITERAL(1, 32, 13), // "Slot_ClickAdd"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 7), // "checked"
QT_MOC_LITERAL(4, 55, 16), // "Slot_ClickDelete"
QT_MOC_LITERAL(5, 72, 20), // "Slot_ClickAddAddress"
QT_MOC_LITERAL(6, 93, 23), // "Slot_ClickDeleteAddress"
QT_MOC_LITERAL(7, 117, 27), // "Slot_ClickAutomaticGenerate"
QT_MOC_LITERAL(8, 145, 14), // "Slot_ClickSend"
QT_MOC_LITERAL(9, 160, 14), // "SLot_ClickStop"
QT_MOC_LITERAL(10, 175, 22), // "Slot_ClickItemSendList"
QT_MOC_LITERAL(11, 198, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(12, 215, 4), // "item"
QT_MOC_LITERAL(13, 220, 25), // "Slot_ClickCellAddressList"
QT_MOC_LITERAL(14, 246, 3), // "row"
QT_MOC_LITERAL(15, 250, 6), // "column"
QT_MOC_LITERAL(16, 257, 12), // "Slot_Receipt"
QT_MOC_LITERAL(17, 270, 12), // "MessageUnit*"
QT_MOC_LITERAL(18, 283, 12), // "_messageUnit"
QT_MOC_LITERAL(19, 296, 12), // "Slot_TimeOut"
QT_MOC_LITERAL(20, 309, 22), // "Slot_UpdateAddressList"
QT_MOC_LITERAL(21, 332, 7), // "Client*"
QT_MOC_LITERAL(22, 340, 7), // "_client"
QT_MOC_LITERAL(23, 348, 28), // "Slot_UpdateOfflineClientList"
QT_MOC_LITERAL(24, 377, 15), // "QList<Client*>*"
QT_MOC_LITERAL(25, 393, 8) // "_clients"

    },
    "network_st::ServerCommunication\0"
    "Slot_ClickAdd\0\0checked\0Slot_ClickDelete\0"
    "Slot_ClickAddAddress\0Slot_ClickDeleteAddress\0"
    "Slot_ClickAutomaticGenerate\0Slot_ClickSend\0"
    "SLot_ClickStop\0Slot_ClickItemSendList\0"
    "QListWidgetItem*\0item\0Slot_ClickCellAddressList\0"
    "row\0column\0Slot_Receipt\0MessageUnit*\0"
    "_messageUnit\0Slot_TimeOut\0"
    "Slot_UpdateAddressList\0Client*\0_client\0"
    "Slot_UpdateOfflineClientList\0"
    "QList<Client*>*\0_clients"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_network_st__ServerCommunication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x08 /* Private */,
       1,    0,  117,    2, 0x28 /* Private | MethodCloned */,
       4,    1,  118,    2, 0x08 /* Private */,
       4,    0,  121,    2, 0x28 /* Private | MethodCloned */,
       5,    1,  122,    2, 0x08 /* Private */,
       5,    0,  125,    2, 0x28 /* Private | MethodCloned */,
       6,    1,  126,    2, 0x08 /* Private */,
       6,    0,  129,    2, 0x28 /* Private | MethodCloned */,
       7,    1,  130,    2, 0x08 /* Private */,
       7,    0,  133,    2, 0x28 /* Private | MethodCloned */,
       8,    1,  134,    2, 0x08 /* Private */,
       8,    0,  137,    2, 0x28 /* Private | MethodCloned */,
       9,    1,  138,    2, 0x08 /* Private */,
       9,    0,  141,    2, 0x28 /* Private | MethodCloned */,
      10,    1,  142,    2, 0x08 /* Private */,
      13,    2,  145,    2, 0x08 /* Private */,
      16,    1,  150,    2, 0x08 /* Private */,
      19,    0,  153,    2, 0x08 /* Private */,
      20,    1,  154,    2, 0x08 /* Private */,
      23,    1,  157,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 24,   25,

       0        // eod
};

void network_st::ServerCommunication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ServerCommunication *_t = static_cast<ServerCommunication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Slot_ClickAdd((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->Slot_ClickAdd(); break;
        case 2: _t->Slot_ClickDelete((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->Slot_ClickDelete(); break;
        case 4: _t->Slot_ClickAddAddress((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->Slot_ClickAddAddress(); break;
        case 6: _t->Slot_ClickDeleteAddress((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->Slot_ClickDeleteAddress(); break;
        case 8: _t->Slot_ClickAutomaticGenerate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->Slot_ClickAutomaticGenerate(); break;
        case 10: _t->Slot_ClickSend((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->Slot_ClickSend(); break;
        case 12: _t->SLot_ClickStop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->SLot_ClickStop(); break;
        case 14: _t->Slot_ClickItemSendList((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 15: _t->Slot_ClickCellAddressList((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->Slot_Receipt((*reinterpret_cast< MessageUnit*(*)>(_a[1]))); break;
        case 17: _t->Slot_TimeOut(); break;
        case 18: _t->Slot_UpdateAddressList((*reinterpret_cast< Client*(*)>(_a[1]))); break;
        case 19: _t->Slot_UpdateOfflineClientList((*reinterpret_cast< QList<Client*>*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject network_st::ServerCommunication::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_network_st__ServerCommunication.data,
      qt_meta_data_network_st__ServerCommunication,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *network_st::ServerCommunication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *network_st::ServerCommunication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_network_st__ServerCommunication.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int network_st::ServerCommunication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
