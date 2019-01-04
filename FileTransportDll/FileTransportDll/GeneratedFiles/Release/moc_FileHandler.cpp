/****************************************************************************
** Meta object code from reading C++ file 'FileHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FileHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_file_transport_st__FileHandler_t {
    QByteArrayData data[15];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_file_transport_st__FileHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_file_transport_st__FileHandler_t qt_meta_stringdata_file_transport_st__FileHandler = {
    {
QT_MOC_LITERAL(0, 0, 30), // "file_transport_st::FileHandler"
QT_MOC_LITERAL(1, 31, 21), // "Signal_GetUploadReply"
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 9), // "bytesRead"
QT_MOC_LITERAL(4, 64, 10), // "totalBytes"
QT_MOC_LITERAL(5, 75, 23), // "Signal_GetDownloadReply"
QT_MOC_LITERAL(6, 99, 19), // "Slot_CancelDownload"
QT_MOC_LITERAL(7, 119, 17), // "Slot_HttpFinished"
QT_MOC_LITERAL(8, 137, 18), // "Slot_HttpReadyRead"
QT_MOC_LITERAL(9, 156, 24), // "Slot_UploadReplyFinished"
QT_MOC_LITERAL(10, 181, 14), // "QNetworkReply*"
QT_MOC_LITERAL(11, 196, 5), // "reply"
QT_MOC_LITERAL(12, 202, 16), // "Slot_UpLoadError"
QT_MOC_LITERAL(13, 219, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(14, 247, 5) // "error"

    },
    "file_transport_st::FileHandler\0"
    "Signal_GetUploadReply\0\0bytesRead\0"
    "totalBytes\0Signal_GetDownloadReply\0"
    "Slot_CancelDownload\0Slot_HttpFinished\0"
    "Slot_HttpReadyRead\0Slot_UploadReplyFinished\0"
    "QNetworkReply*\0reply\0Slot_UpLoadError\0"
    "QNetworkReply::NetworkError\0error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_file_transport_st__FileHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    1,   62,    2, 0x08 /* Private */,
      12,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void file_transport_st::FileHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileHandler *_t = static_cast<FileHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Signal_GetUploadReply((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: _t->Signal_GetDownloadReply((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 2: _t->Slot_CancelDownload(); break;
        case 3: _t->Slot_HttpFinished(); break;
        case 4: _t->Slot_HttpReadyRead(); break;
        case 5: _t->Slot_UploadReplyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->Slot_UpLoadError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (FileHandler::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileHandler::Signal_GetUploadReply)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FileHandler::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileHandler::Signal_GetDownloadReply)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject file_transport_st::FileHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_file_transport_st__FileHandler.data,
      qt_meta_data_file_transport_st__FileHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *file_transport_st::FileHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *file_transport_st::FileHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_file_transport_st__FileHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int file_transport_st::FileHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void file_transport_st::FileHandler::Signal_GetUploadReply(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void file_transport_st::FileHandler::Signal_GetDownloadReply(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
