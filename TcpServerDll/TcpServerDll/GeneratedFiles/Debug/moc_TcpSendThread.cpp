/****************************************************************************
** Meta object code from reading C++ file 'TcpSendThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TcpSendThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TcpSendThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_network_server_st__TcpSendThread_t {
    QByteArrayData data[3];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_network_server_st__TcpSendThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_network_server_st__TcpSendThread_t qt_meta_stringdata_network_server_st__TcpSendThread = {
    {
QT_MOC_LITERAL(0, 0, 32), // "network_server_st::TcpSendThread"
QT_MOC_LITERAL(1, 33, 18), // "Slot_NewConnection"
QT_MOC_LITERAL(2, 52, 0) // ""

    },
    "network_server_st::TcpSendThread\0"
    "Slot_NewConnection\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_network_server_st__TcpSendThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void network_server_st::TcpSendThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpSendThread *_t = static_cast<TcpSendThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Slot_NewConnection(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject network_server_st::TcpSendThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_network_server_st__TcpSendThread.data,
      qt_meta_data_network_server_st__TcpSendThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *network_server_st::TcpSendThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *network_server_st::TcpSendThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_network_server_st__TcpSendThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int network_server_st::TcpSendThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
