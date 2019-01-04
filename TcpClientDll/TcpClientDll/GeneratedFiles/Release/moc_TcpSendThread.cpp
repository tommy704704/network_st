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
struct qt_meta_stringdata_network_st__TcpSendThread_t {
    QByteArrayData data[7];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_network_st__TcpSendThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_network_st__TcpSendThread_t qt_meta_stringdata_network_st__TcpSendThread = {
    {
QT_MOC_LITERAL(0, 0, 25), // "network_st::TcpSendThread"
QT_MOC_LITERAL(1, 26, 18), // "Signal_SendMessage"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 12), // "MessageUnit*"
QT_MOC_LITERAL(4, 59, 12), // "_messageUnit"
QT_MOC_LITERAL(5, 72, 30), // "Signal_UpdateUITcpReplyMessage"
QT_MOC_LITERAL(6, 103, 16) // "Slot_SendMessage"

    },
    "network_st::TcpSendThread\0Signal_SendMessage\0"
    "\0MessageUnit*\0_messageUnit\0"
    "Signal_UpdateUITcpReplyMessage\0"
    "Slot_SendMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_network_st__TcpSendThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void network_st::TcpSendThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpSendThread *_t = static_cast<TcpSendThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Signal_SendMessage((*reinterpret_cast< MessageUnit*(*)>(_a[1]))); break;
        case 1: _t->Signal_UpdateUITcpReplyMessage((*reinterpret_cast< MessageUnit*(*)>(_a[1]))); break;
        case 2: _t->Slot_SendMessage((*reinterpret_cast< MessageUnit*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TcpSendThread::*_t)(MessageUnit * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSendThread::Signal_SendMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TcpSendThread::*_t)(MessageUnit * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSendThread::Signal_UpdateUITcpReplyMessage)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject network_st::TcpSendThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_network_st__TcpSendThread.data,
      qt_meta_data_network_st__TcpSendThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *network_st::TcpSendThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *network_st::TcpSendThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_network_st__TcpSendThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int network_st::TcpSendThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void network_st::TcpSendThread::Signal_SendMessage(MessageUnit * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void network_st::TcpSendThread::Signal_UpdateUITcpReplyMessage(MessageUnit * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
