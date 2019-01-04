/****************************************************************************
** Meta object code from reading C++ file 'FileServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FileServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_file_transport_st__FileServer_t {
    QByteArrayData data[12];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_file_transport_st__FileServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_file_transport_st__FileServer_t qt_meta_stringdata_file_transport_st__FileServer = {
    {
QT_MOC_LITERAL(0, 0, 29), // "file_transport_st::FileServer"
QT_MOC_LITERAL(1, 30, 17), // "Slot_DownloadFile"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 15), // "Slot_SelectFile"
QT_MOC_LITERAL(4, 65, 7), // "checked"
QT_MOC_LITERAL(5, 73, 13), // "Slot_SendFile"
QT_MOC_LITERAL(6, 87, 27), // "Slot_UpdateDataReadProgress"
QT_MOC_LITERAL(7, 115, 9), // "bytesRead"
QT_MOC_LITERAL(8, 125, 10), // "totalBytes"
QT_MOC_LITERAL(9, 136, 21), // "Slot_OnUploadProgress"
QT_MOC_LITERAL(10, 158, 9), // "bytesSent"
QT_MOC_LITERAL(11, 168, 10) // "bytesTotal"

    },
    "file_transport_st::FileServer\0"
    "Slot_DownloadFile\0\0Slot_SelectFile\0"
    "checked\0Slot_SendFile\0Slot_UpdateDataReadProgress\0"
    "bytesRead\0totalBytes\0Slot_OnUploadProgress\0"
    "bytesSent\0bytesTotal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_file_transport_st__FileServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    1,   50,    2, 0x08 /* Private */,
       3,    0,   53,    2, 0x28 /* Private | MethodCloned */,
       5,    1,   54,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x28 /* Private | MethodCloned */,
       6,    2,   58,    2, 0x08 /* Private */,
       9,    2,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    7,    8,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   10,   11,

       0        // eod
};

void file_transport_st::FileServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileServer *_t = static_cast<FileServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Slot_DownloadFile(); break;
        case 1: _t->Slot_SelectFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->Slot_SelectFile(); break;
        case 3: _t->Slot_SendFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->Slot_SendFile(); break;
        case 5: _t->Slot_UpdateDataReadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 6: _t->Slot_OnUploadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject file_transport_st::FileServer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_file_transport_st__FileServer.data,
      qt_meta_data_file_transport_st__FileServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *file_transport_st::FileServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *file_transport_st::FileServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_file_transport_st__FileServer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int file_transport_st::FileServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
