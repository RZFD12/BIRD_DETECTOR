/****************************************************************************
** Meta object code from reading C++ file 'imgdata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../imgdata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imgdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImgData_t {
    QByteArrayData data[19];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImgData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImgData_t qt_meta_stringdata_ImgData = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ImgData"
QT_MOC_LITERAL(1, 8, 10), // "Downloaded"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "Image"
QT_MOC_LITERAL(4, 26, 3), // "pix"
QT_MOC_LITERAL(5, 30, 14), // "set_image_data"
QT_MOC_LITERAL(6, 45, 21), // "image_saving_protocol"
QT_MOC_LITERAL(7, 67, 1), // "p"
QT_MOC_LITERAL(8, 69, 12), // "setThresHold"
QT_MOC_LITERAL(9, 82, 2), // "bs"
QT_MOC_LITERAL(10, 85, 1), // "C"
QT_MOC_LITERAL(11, 87, 9), // "imgFilter"
QT_MOC_LITERAL(12, 97, 5), // "state"
QT_MOC_LITERAL(13, 103, 6), // "filter"
QT_MOC_LITERAL(14, 110, 5), // "Start"
QT_MOC_LITERAL(15, 116, 14), // "setFileHandler"
QT_MOC_LITERAL(16, 131, 12), // "FileHandler*"
QT_MOC_LITERAL(17, 144, 1), // "f"
QT_MOC_LITERAL(18, 146, 3) // "Get"

    },
    "ImgData\0Downloaded\0\0Image\0pix\0"
    "set_image_data\0image_saving_protocol\0"
    "p\0setThresHold\0bs\0C\0imgFilter\0state\0"
    "filter\0Start\0setFileHandler\0FileHandler*\0"
    "f\0Get"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImgData[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       5,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   61,    2, 0x0a /* Public */,
      11,    1,   66,    2, 0x0a /* Public */,
      14,    0,   69,    2, 0x0a /* Public */,
      15,    1,   70,    2, 0x0a /* Public */,
      18,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Double,    9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,

       0        // eod
};

void ImgData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImgData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Downloaded(); break;
        case 1: _t->Image((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 2: _t->set_image_data((*reinterpret_cast< image_saving_protocol(*)>(_a[1]))); break;
        case 3: _t->setThresHold((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: _t->imgFilter((*reinterpret_cast< state(*)>(_a[1]))); break;
        case 5: _t->Start(); break;
        case 6: _t->setFileHandler((*reinterpret_cast< FileHandler*(*)>(_a[1]))); break;
        case 7: _t->Get(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< image_saving_protocol >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FileHandler* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ImgData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImgData::Downloaded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ImgData::*)(QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImgData::Image)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ImgData::*)(image_saving_protocol );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImgData::set_image_data)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ImgData::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ImgData.data,
    qt_meta_data_ImgData,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ImgData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImgData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImgData.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ImgData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ImgData::Downloaded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ImgData::Image(QPixmap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ImgData::set_image_data(image_saving_protocol _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
