/****************************************************************************
** Meta object code from reading C++ file 'UdpSendThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UdpSendThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UdpSendThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_network_st__UdpSendThread_t {
    QByteArrayData data[5];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_network_st__UdpSendThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_network_st__UdpSendThread_t qt_meta_stringdata_network_st__UdpSendThread = {
    {
QT_MOC_LITERAL(0, 0, 25), // "network_st::UdpSendThread"
QT_MOC_LITERAL(1, 26, 31), // "Signal_UpdateOfflineAddressList"
QT_MOC_LITERAL(2, 58, 0), // ""
QT_MOC_LITERAL(3, 59, 15), // "QList<Client*>*"
QT_MOC_LITERAL(4, 75, 8) // "_clients"

    },
    "network_st::UdpSendThread\0"
    "Signal_UpdateOfflineAddressList\0\0"
    "QList<Client*>*\0_clients"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_network_st__UdpSendThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void network_st::UdpSendThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UdpSendThread *_t = static_cast<UdpSendThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Signal_UpdateOfflineAddressList((*reinterpret_cast< QList<Client*>*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (UdpSendThread::*_t)(QList<Client*> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UdpSendThread::Signal_UpdateOfflineAddressList)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject network_st::UdpSendThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_network_st__UdpSendThread.data,
      qt_meta_data_network_st__UdpSendThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *network_st::UdpSendThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *network_st::UdpSendThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_network_st__UdpSendThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int network_st::UdpSendThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void network_st::UdpSendThread::Signal_UpdateOfflineAddressList(QList<Client*> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
