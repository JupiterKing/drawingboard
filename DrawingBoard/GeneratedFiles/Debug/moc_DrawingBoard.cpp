/****************************************************************************
** Meta object code from reading C++ file 'DrawingBoard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrawingBoard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DrawingBoard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DrawingBoard_t {
    QByteArrayData data[31];
    char stringdata0[423];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawingBoard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawingBoard_t qt_meta_stringdata_DrawingBoard = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DrawingBoard"
QT_MOC_LITERAL(1, 13, 14), // "operation_open"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14), // "operation_load"
QT_MOC_LITERAL(4, 44, 3), // "img"
QT_MOC_LITERAL(5, 48, 14), // "operation_undo"
QT_MOC_LITERAL(6, 63, 14), // "operation_redo"
QT_MOC_LITERAL(7, 78, 20), // "operation_mouseCheck"
QT_MOC_LITERAL(8, 99, 17), // "operation_pensize"
QT_MOC_LITERAL(9, 117, 5), // "iSize"
QT_MOC_LITERAL(10, 123, 14), // "operation_text"
QT_MOC_LITERAL(11, 138, 9), // "iFontSize"
QT_MOC_LITERAL(12, 148, 15), // "operation_shape"
QT_MOC_LITERAL(13, 164, 9), // "ShapeType"
QT_MOC_LITERAL(14, 174, 5), // "eType"
QT_MOC_LITERAL(15, 180, 15), // "operation_color"
QT_MOC_LITERAL(16, 196, 5), // "color"
QT_MOC_LITERAL(17, 202, 16), // "operation_eraser"
QT_MOC_LITERAL(18, 219, 16), // "operation_expand"
QT_MOC_LITERAL(19, 236, 15), // "ExpandDirection"
QT_MOC_LITERAL(20, 252, 9), // "direction"
QT_MOC_LITERAL(21, 262, 18), // "operation_rotation"
QT_MOC_LITERAL(22, 281, 16), // "RotationDirecton"
QT_MOC_LITERAL(23, 298, 14), // "operation_zoom"
QT_MOC_LITERAL(24, 313, 9), // "izoomrate"
QT_MOC_LITERAL(25, 323, 14), // "operation_save"
QT_MOC_LITERAL(26, 338, 7), // "QImage&"
QT_MOC_LITERAL(27, 346, 15), // "operation_decal"
QT_MOC_LITERAL(28, 362, 19), // "operation_clearArea"
QT_MOC_LITERAL(29, 382, 18), // "operation_fillArea"
QT_MOC_LITERAL(30, 401, 21) // "operation_screenshots"

    },
    "DrawingBoard\0operation_open\0\0"
    "operation_load\0img\0operation_undo\0"
    "operation_redo\0operation_mouseCheck\0"
    "operation_pensize\0iSize\0operation_text\0"
    "iFontSize\0operation_shape\0ShapeType\0"
    "eType\0operation_color\0color\0"
    "operation_eraser\0operation_expand\0"
    "ExpandDirection\0direction\0operation_rotation\0"
    "RotationDirecton\0operation_zoom\0"
    "izoomrate\0operation_save\0QImage&\0"
    "operation_decal\0operation_clearArea\0"
    "operation_fillArea\0operation_screenshots"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawingBoard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    1,  105,    2, 0x0a /* Public */,
       5,    0,  108,    2, 0x0a /* Public */,
       6,    0,  109,    2, 0x0a /* Public */,
       7,    0,  110,    2, 0x0a /* Public */,
       8,    1,  111,    2, 0x0a /* Public */,
      10,    1,  114,    2, 0x0a /* Public */,
      12,    1,  117,    2, 0x0a /* Public */,
      15,    1,  120,    2, 0x0a /* Public */,
      17,    1,  123,    2, 0x0a /* Public */,
      18,    1,  126,    2, 0x0a /* Public */,
      21,    1,  129,    2, 0x0a /* Public */,
      23,    1,  132,    2, 0x0a /* Public */,
      25,    1,  135,    2, 0x0a /* Public */,
      27,    0,  138,    2, 0x0a /* Public */,
      28,    0,  139,    2, 0x0a /* Public */,
      29,    1,  140,    2, 0x0a /* Public */,
      30,    0,  143,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::QColor,   16,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 22,   20,
    QMetaType::Void, QMetaType::QReal,   24,
    QMetaType::Void, 0x80000000 | 26,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,   16,
    QMetaType::Void,

       0        // eod
};

void DrawingBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DrawingBoard *_t = static_cast<DrawingBoard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->operation_open(); break;
        case 1: _t->operation_load((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 2: _t->operation_undo(); break;
        case 3: _t->operation_redo(); break;
        case 4: _t->operation_mouseCheck(); break;
        case 5: _t->operation_pensize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->operation_text((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->operation_shape((*reinterpret_cast< ShapeType(*)>(_a[1]))); break;
        case 8: _t->operation_color((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 9: _t->operation_eraser((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->operation_expand((*reinterpret_cast< ExpandDirection(*)>(_a[1]))); break;
        case 11: _t->operation_rotation((*reinterpret_cast< RotationDirecton(*)>(_a[1]))); break;
        case 12: _t->operation_zoom((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 13: _t->operation_save((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 14: _t->operation_decal(); break;
        case 15: _t->operation_clearArea(); break;
        case 16: _t->operation_fillArea((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 17: _t->operation_screenshots(); break;
        default: ;
        }
    }
}

const QMetaObject DrawingBoard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DrawingBoard.data,
      qt_meta_data_DrawingBoard,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DrawingBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawingBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DrawingBoard.stringdata0))
        return static_cast<void*>(const_cast< DrawingBoard*>(this));
    return QWidget::qt_metacast(_clname);
}

int DrawingBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
