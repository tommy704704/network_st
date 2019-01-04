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
    QByteArrayData data[15];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_file_transport_st__FileServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_file_transport_st__FileServer_t qt_meta_stringdata_file_transport_st__FileServer = {
    {
QT_MOC_LITERAL(0, 0, 29), // "file_transport_st::FileServer"
QT_MOC_LITERAL(1, 30, 21), // "Signal_GetUploadReply"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 9), // "bytesRead"
QT_MOC_LITERAL(4, 63, 10), // "totalBytes"
QT_MOC_LITERAL(5, 74, 23), // "Signal_GetDownloadReply"
QT_MOC_LITERAL(6, 98, 17), // "Slot_DownloadFile"
QT_MOC_LITERAL(7, 116, 15), // "Slot_SelectFile"
QT_MOC_LITERAL(8, 132, 7), // "checked"
QT_MOC_LITERAL(9, 140, 13), // "Slot_SendFile"
QT_MOC_LITERAL(10, 154, 27), // "Slot_UpdateDataReadProgress"
QT_MOC_LITERAL(11, 182, 21), // "Slot_OnUploadProgress"
QT_MOC_LITERAL(12, 204, 9), // "bytesSent"
QT_MOC_LITERAL(13, 214, 10), // "bytesTotal"
QT_MOC_LITERAL(14, 225, 13) // "Slot_OnUpload"

    },
    "file_transport_st::FileServer\0"
    "Signal_GetUploadReply\0\0bytesRead\0"
    "totalBytes\0Signal_GetDownloadReply\0"
    "Slot_DownloadFile\0Slot_SelectFile\0"
    "checked\0Slot_SendFile\0Slot_UpdateDataReadProgress\0"
    "Slot_OnUploadProgress\0bytesSent\0"
    "bytesTotal\0Slot_OnUpload"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_file_transport_st__FileServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    2,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   74,    2, 0x08 /* Private */,
       7,    1,   75,    2, 0x08 /* Private */,
       7,    0,   78,    2, 0x28 /* Private | MethodCloned */,
       9,    1,   79,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x28 /* Private | MethodCloned */,
      10,    2,   83,    2, 0x08 /* Private */,
      11,    2,   88,    2, 0x08 /* Private */,
      14,    2,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   12,   13,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   12,   13,

       0        // eod
};

void file_transport_st::FileServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileServer *_t = static_cast<FileServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Signal_GetUploadReply((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: _t->Signal_GetDownloadReply((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 2: _t->Slot_DownloadFile(); break;
        case 3: _t->Slot_SelectFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->Slot_SelectFile(); break;
        case 5: _t->Slot_SendFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->Slot_SendFile(); break;
        case 7: _t->Slot_UpdateDataReadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 8: _t->Slot_OnUploadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 9: _t->Slot_OnUpload((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (FileServer::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileServer::Signal_GetUploadReply)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FileServer::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileServer::Signal_GetDownloadReply)) {
                *result = 1;
                return;
            }
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void file_transport_st::FileServer::Signal_GetUploadReply(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void file_transport_st::FileServer::Signal_GetDownloadReply(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
