/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CamScene_t {
    QByteArrayData data[1];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CamScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CamScene_t qt_meta_stringdata_CamScene = {
    {
QT_MOC_LITERAL(0, 0, 8) // "CamScene"

    },
    "CamScene"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CamScene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CamScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CamScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_CamScene.data,
    qt_meta_data_CamScene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CamScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CamScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CamScene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int CamScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[39];
    char stringdata0[622];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "thresHold"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 2), // "bs"
QT_MOC_LITERAL(4, 25, 1), // "C"
QT_MOC_LITERAL(5, 27, 9), // "imgFilter"
QT_MOC_LITERAL(6, 37, 5), // "state"
QT_MOC_LITERAL(7, 43, 6), // "filter"
QT_MOC_LITERAL(8, 50, 7), // "loadImg"
QT_MOC_LITERAL(9, 58, 11), // "loadImgLeft"
QT_MOC_LITERAL(10, 70, 6), // "piximg"
QT_MOC_LITERAL(11, 77, 12), // "loadImgRight"
QT_MOC_LITERAL(12, 90, 14), // "IndexingStatus"
QT_MOC_LITERAL(13, 105, 1), // "p"
QT_MOC_LITERAL(14, 107, 25), // "on_toolButtonNext_clicked"
QT_MOC_LITERAL(15, 133, 25), // "on_toolButtonPlay_clicked"
QT_MOC_LITERAL(16, 159, 25), // "on_toolButtonPrev_clicked"
QT_MOC_LITERAL(17, 185, 13), // "keyPressEvent"
QT_MOC_LITERAL(18, 199, 10), // "QKeyEvent*"
QT_MOC_LITERAL(19, 210, 5), // "event"
QT_MOC_LITERAL(20, 216, 9), // "addMixmap"
QT_MOC_LITERAL(21, 226, 11), // "QByteArray&"
QT_MOC_LITERAL(22, 238, 4), // "data"
QT_MOC_LITERAL(23, 243, 38), // "on_horizontalSliderBlsize_val..."
QT_MOC_LITERAL(24, 282, 5), // "value"
QT_MOC_LITERAL(25, 288, 33), // "on_horizontalSliderC_valueCha..."
QT_MOC_LITERAL(26, 322, 11), // "imageFilter"
QT_MOC_LITERAL(27, 334, 25), // "on_toolButtonSave_pressed"
QT_MOC_LITERAL(28, 360, 25), // "on_toolButtonOpen_pressed"
QT_MOC_LITERAL(29, 386, 26), // "on_pushButtonApply_clicked"
QT_MOC_LITERAL(30, 413, 27), // "on_pushButtonDelete_clicked"
QT_MOC_LITERAL(31, 441, 25), // "on_pushButtonMove_clicked"
QT_MOC_LITERAL(32, 467, 30), // "on_spinBoxRotLeft_valueChanged"
QT_MOC_LITERAL(33, 498, 4), // "arg1"
QT_MOC_LITERAL(34, 503, 31), // "on_spinBoxRotRight_valueChanged"
QT_MOC_LITERAL(35, 535, 11), // "init3DGraph"
QT_MOC_LITERAL(36, 547, 4), // "To3D"
QT_MOC_LITERAL(37, 552, 34), // "on_doubleSpinBoxRange_valueCh..."
QT_MOC_LITERAL(38, 587, 34) // "on_doubleSpinBoxAngle_valueCh..."

    },
    "MainWindow\0thresHold\0\0bs\0C\0imgFilter\0"
    "state\0filter\0loadImg\0loadImgLeft\0"
    "piximg\0loadImgRight\0IndexingStatus\0p\0"
    "on_toolButtonNext_clicked\0"
    "on_toolButtonPlay_clicked\0"
    "on_toolButtonPrev_clicked\0keyPressEvent\0"
    "QKeyEvent*\0event\0addMixmap\0QByteArray&\0"
    "data\0on_horizontalSliderBlsize_valueChanged\0"
    "value\0on_horizontalSliderC_valueChanged\0"
    "imageFilter\0on_toolButtonSave_pressed\0"
    "on_toolButtonOpen_pressed\0"
    "on_pushButtonApply_clicked\0"
    "on_pushButtonDelete_clicked\0"
    "on_pushButtonMove_clicked\0"
    "on_spinBoxRotLeft_valueChanged\0arg1\0"
    "on_spinBoxRotRight_valueChanged\0"
    "init3DGraph\0To3D\0on_doubleSpinBoxRange_valueChanged\0"
    "on_doubleSpinBoxAngle_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  139,    2, 0x06 /* Public */,
       5,    1,  144,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  147,    2, 0x0a /* Public */,
       9,    1,  148,    2, 0x0a /* Public */,
      11,    1,  151,    2, 0x0a /* Public */,
      12,    1,  154,    2, 0x0a /* Public */,
      14,    0,  157,    2, 0x08 /* Private */,
      15,    0,  158,    2, 0x08 /* Private */,
      16,    0,  159,    2, 0x08 /* Private */,
      17,    1,  160,    2, 0x08 /* Private */,
      20,    1,  163,    2, 0x08 /* Private */,
      23,    1,  166,    2, 0x08 /* Private */,
      25,    1,  169,    2, 0x08 /* Private */,
      26,    0,  172,    2, 0x08 /* Private */,
      27,    0,  173,    2, 0x08 /* Private */,
      28,    0,  174,    2, 0x08 /* Private */,
      29,    0,  175,    2, 0x08 /* Private */,
      30,    0,  176,    2, 0x08 /* Private */,
      31,    0,  177,    2, 0x08 /* Private */,
      32,    1,  178,    2, 0x08 /* Private */,
      34,    1,  181,    2, 0x08 /* Private */,
      35,    0,  184,    2, 0x08 /* Private */,
      36,    0,  185,    2, 0x08 /* Private */,
      37,    1,  186,    2, 0x08 /* Private */,
      38,    1,  189,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Double,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,   10,
    QMetaType::Void, QMetaType::QPixmap,   10,
    QMetaType::Void, QMetaType::QPoint,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   33,
    QMetaType::Void, QMetaType::Double,   33,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->thresHold((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->imgFilter((*reinterpret_cast< state(*)>(_a[1]))); break;
        case 2: _t->loadImg(); break;
        case 3: _t->loadImgLeft((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 4: _t->loadImgRight((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 5: _t->IndexingStatus((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->on_toolButtonNext_clicked(); break;
        case 7: _t->on_toolButtonPlay_clicked(); break;
        case 8: _t->on_toolButtonPrev_clicked(); break;
        case 9: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 10: _t->addMixmap((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 11: _t->on_horizontalSliderBlsize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_horizontalSliderC_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->imageFilter(); break;
        case 14: _t->on_toolButtonSave_pressed(); break;
        case 15: _t->on_toolButtonOpen_pressed(); break;
        case 16: _t->on_pushButtonApply_clicked(); break;
        case 17: _t->on_pushButtonDelete_clicked(); break;
        case 18: _t->on_pushButtonMove_clicked(); break;
        case 19: _t->on_spinBoxRotLeft_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_spinBoxRotRight_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->init3DGraph(); break;
        case 22: _t->To3D(); break;
        case 23: _t->on_doubleSpinBoxRange_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 24: _t->on_doubleSpinBoxAngle_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::thresHold)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(state );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::imgFilter)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::thresHold(int _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::imgFilter(state _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
