/****************************************************************************
** Meta object code from reading C++ file 'boardwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../boardwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boardwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BoardWidget_t {
    QByteArrayData data[89];
    char stringdata0[1209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BoardWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BoardWidget_t qt_meta_stringdata_BoardWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "BoardWidget"
QT_MOC_LITERAL(1, 12, 11), // "signal_open"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "signal_undo"
QT_MOC_LITERAL(4, 37, 11), // "signal_redo"
QT_MOC_LITERAL(5, 49, 18), // "signal_toolChanged"
QT_MOC_LITERAL(6, 68, 17), // "tools::Tool::Type"
QT_MOC_LITERAL(7, 86, 4), // "tool"
QT_MOC_LITERAL(8, 91, 12), // "signal_mouse"
QT_MOC_LITERAL(9, 104, 18), // "signal_brushChange"
QT_MOC_LITERAL(10, 123, 15), // "signal_textsize"
QT_MOC_LITERAL(11, 139, 9), // "iFontSize"
QT_MOC_LITERAL(12, 149, 12), // "signal_color"
QT_MOC_LITERAL(13, 162, 5), // "color"
QT_MOC_LITERAL(14, 168, 12), // "signal_decal"
QT_MOC_LITERAL(15, 181, 15), // "signal_expandup"
QT_MOC_LITERAL(16, 197, 18), // "signal_expandright"
QT_MOC_LITERAL(17, 216, 17), // "signal_expanddown"
QT_MOC_LITERAL(18, 234, 17), // "signal_expandleft"
QT_MOC_LITERAL(19, 252, 11), // "signal_zoom"
QT_MOC_LITERAL(20, 264, 9), // "izoomrate"
QT_MOC_LITERAL(21, 274, 13), // "signal_zoomin"
QT_MOC_LITERAL(22, 288, 14), // "signal_zoomout"
QT_MOC_LITERAL(23, 303, 15), // "signal_zoomorig"
QT_MOC_LITERAL(24, 319, 17), // "signal_rotateorig"
QT_MOC_LITERAL(25, 337, 15), // "signal_rotatecw"
QT_MOC_LITERAL(26, 353, 16), // "signal_rotateccw"
QT_MOC_LITERAL(27, 370, 15), // "signal_rotate90"
QT_MOC_LITERAL(28, 386, 16), // "signal_rotate180"
QT_MOC_LITERAL(29, 403, 16), // "signal_rotate270"
QT_MOC_LITERAL(30, 420, 15), // "signal_viewflip"
QT_MOC_LITERAL(31, 436, 5), // "bflip"
QT_MOC_LITERAL(32, 442, 17), // "signal_viewmirror"
QT_MOC_LITERAL(33, 460, 7), // "bmirror"
QT_MOC_LITERAL(34, 468, 16), // "signal_clearArea"
QT_MOC_LITERAL(35, 485, 15), // "signal_fillArea"
QT_MOC_LITERAL(36, 501, 22), // "signal_showannotations"
QT_MOC_LITERAL(37, 524, 5), // "bshow"
QT_MOC_LITERAL(38, 530, 21), // "signal_showuserlayers"
QT_MOC_LITERAL(39, 552, 17), // "signal_showlasers"
QT_MOC_LITERAL(40, 570, 14), // "operation_open"
QT_MOC_LITERAL(41, 585, 14), // "operation_load"
QT_MOC_LITERAL(42, 600, 3), // "img"
QT_MOC_LITERAL(43, 604, 14), // "operation_undo"
QT_MOC_LITERAL(44, 619, 14), // "operation_redo"
QT_MOC_LITERAL(45, 634, 20), // "operation_mouseCheck"
QT_MOC_LITERAL(46, 655, 17), // "operation_pensize"
QT_MOC_LITERAL(47, 673, 5), // "iSize"
QT_MOC_LITERAL(48, 679, 14), // "operation_text"
QT_MOC_LITERAL(49, 694, 15), // "operation_shape"
QT_MOC_LITERAL(50, 710, 9), // "ShapeType"
QT_MOC_LITERAL(51, 720, 5), // "eType"
QT_MOC_LITERAL(52, 726, 15), // "operation_color"
QT_MOC_LITERAL(53, 742, 16), // "operation_eraser"
QT_MOC_LITERAL(54, 759, 15), // "operation_decal"
QT_MOC_LITERAL(55, 775, 19), // "operation_clearArea"
QT_MOC_LITERAL(56, 795, 18), // "operation_fillArea"
QT_MOC_LITERAL(57, 814, 16), // "operation_expand"
QT_MOC_LITERAL(58, 831, 15), // "ExpandDirection"
QT_MOC_LITERAL(59, 847, 9), // "direction"
QT_MOC_LITERAL(60, 857, 18), // "operation_rotation"
QT_MOC_LITERAL(61, 876, 16), // "RotationDirecton"
QT_MOC_LITERAL(62, 893, 14), // "operation_zoom"
QT_MOC_LITERAL(63, 908, 14), // "operation_save"
QT_MOC_LITERAL(64, 923, 7), // "QImage&"
QT_MOC_LITERAL(65, 931, 21), // "operation_screenshots"
QT_MOC_LITERAL(66, 953, 7), // "showNew"
QT_MOC_LITERAL(67, 961, 4), // "open"
QT_MOC_LITERAL(68, 966, 3), // "url"
QT_MOC_LITERAL(69, 970, 4), // "save"
QT_MOC_LITERAL(70, 975, 8), // "filename"
QT_MOC_LITERAL(71, 984, 11), // "newDocument"
QT_MOC_LITERAL(72, 996, 4), // "size"
QT_MOC_LITERAL(73, 1001, 10), // "background"
QT_MOC_LITERAL(74, 1012, 23), // "updateTabletSupportMode"
QT_MOC_LITERAL(75, 1036, 5), // "paste"
QT_MOC_LITERAL(76, 1042, 10), // "pasteImage"
QT_MOC_LITERAL(77, 1053, 5), // "image"
QT_MOC_LITERAL(78, 1059, 13), // "const QPoint*"
QT_MOC_LITERAL(79, 1073, 5), // "point"
QT_MOC_LITERAL(80, 1079, 13), // "clearOrDelete"
QT_MOC_LITERAL(81, 1093, 12), // "resizeCanvas"
QT_MOC_LITERAL(82, 1106, 11), // "toolChanged"
QT_MOC_LITERAL(83, 1118, 15), // "onCanvasChanged"
QT_MOC_LITERAL(84, 1134, 20), // "canvas::CanvasModel*"
QT_MOC_LITERAL(85, 1155, 6), // "canvas"
QT_MOC_LITERAL(86, 1162, 19), // "onCanvasSaveStarted"
QT_MOC_LITERAL(87, 1182, 13), // "onCanvasSaved"
QT_MOC_LITERAL(88, 1196, 12) // "errorMessage"

    },
    "BoardWidget\0signal_open\0\0signal_undo\0"
    "signal_redo\0signal_toolChanged\0"
    "tools::Tool::Type\0tool\0signal_mouse\0"
    "signal_brushChange\0signal_textsize\0"
    "iFontSize\0signal_color\0color\0signal_decal\0"
    "signal_expandup\0signal_expandright\0"
    "signal_expanddown\0signal_expandleft\0"
    "signal_zoom\0izoomrate\0signal_zoomin\0"
    "signal_zoomout\0signal_zoomorig\0"
    "signal_rotateorig\0signal_rotatecw\0"
    "signal_rotateccw\0signal_rotate90\0"
    "signal_rotate180\0signal_rotate270\0"
    "signal_viewflip\0bflip\0signal_viewmirror\0"
    "bmirror\0signal_clearArea\0signal_fillArea\0"
    "signal_showannotations\0bshow\0"
    "signal_showuserlayers\0signal_showlasers\0"
    "operation_open\0operation_load\0img\0"
    "operation_undo\0operation_redo\0"
    "operation_mouseCheck\0operation_pensize\0"
    "iSize\0operation_text\0operation_shape\0"
    "ShapeType\0eType\0operation_color\0"
    "operation_eraser\0operation_decal\0"
    "operation_clearArea\0operation_fillArea\0"
    "operation_expand\0ExpandDirection\0"
    "direction\0operation_rotation\0"
    "RotationDirecton\0operation_zoom\0"
    "operation_save\0QImage&\0operation_screenshots\0"
    "showNew\0open\0url\0save\0filename\0"
    "newDocument\0size\0background\0"
    "updateTabletSupportMode\0paste\0pasteImage\0"
    "image\0const QPoint*\0point\0clearOrDelete\0"
    "resizeCanvas\0toolChanged\0onCanvasChanged\0"
    "canvas::CanvasModel*\0canvas\0"
    "onCanvasSaveStarted\0onCanvasSaved\0"
    "errorMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BoardWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      63,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      30,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  329,    2, 0x06 /* Public */,
       3,    0,  330,    2, 0x06 /* Public */,
       4,    0,  331,    2, 0x06 /* Public */,
       5,    1,  332,    2, 0x06 /* Public */,
       8,    0,  335,    2, 0x06 /* Public */,
       9,    1,  336,    2, 0x06 /* Public */,
      10,    1,  339,    2, 0x06 /* Public */,
      12,    1,  342,    2, 0x06 /* Public */,
      14,    0,  345,    2, 0x06 /* Public */,
      15,    0,  346,    2, 0x06 /* Public */,
      16,    0,  347,    2, 0x06 /* Public */,
      17,    0,  348,    2, 0x06 /* Public */,
      18,    0,  349,    2, 0x06 /* Public */,
      19,    1,  350,    2, 0x06 /* Public */,
      21,    0,  353,    2, 0x06 /* Public */,
      22,    0,  354,    2, 0x06 /* Public */,
      23,    0,  355,    2, 0x06 /* Public */,
      24,    0,  356,    2, 0x06 /* Public */,
      25,    0,  357,    2, 0x06 /* Public */,
      26,    0,  358,    2, 0x06 /* Public */,
      27,    0,  359,    2, 0x06 /* Public */,
      28,    0,  360,    2, 0x06 /* Public */,
      29,    0,  361,    2, 0x06 /* Public */,
      30,    1,  362,    2, 0x06 /* Public */,
      32,    1,  365,    2, 0x06 /* Public */,
      34,    0,  368,    2, 0x06 /* Public */,
      35,    1,  369,    2, 0x06 /* Public */,
      36,    1,  372,    2, 0x06 /* Public */,
      38,    1,  375,    2, 0x06 /* Public */,
      39,    1,  378,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      40,    0,  381,    2, 0x0a /* Public */,
      41,    1,  382,    2, 0x0a /* Public */,
      43,    0,  385,    2, 0x0a /* Public */,
      44,    0,  386,    2, 0x0a /* Public */,
      45,    0,  387,    2, 0x0a /* Public */,
      46,    1,  388,    2, 0x0a /* Public */,
      48,    1,  391,    2, 0x0a /* Public */,
      49,    1,  394,    2, 0x0a /* Public */,
      52,    1,  397,    2, 0x0a /* Public */,
      53,    1,  400,    2, 0x0a /* Public */,
      54,    0,  403,    2, 0x0a /* Public */,
      55,    0,  404,    2, 0x0a /* Public */,
      56,    1,  405,    2, 0x0a /* Public */,
      57,    1,  408,    2, 0x0a /* Public */,
      60,    1,  411,    2, 0x0a /* Public */,
      62,    1,  414,    2, 0x0a /* Public */,
      63,    1,  417,    2, 0x0a /* Public */,
      65,    0,  420,    2, 0x0a /* Public */,
      66,    0,  421,    2, 0x0a /* Public */,
      67,    0,  422,    2, 0x0a /* Public */,
      67,    1,  423,    2, 0x0a /* Public */,
      69,    1,  426,    2, 0x0a /* Public */,
      71,    2,  429,    2, 0x0a /* Public */,
      74,    0,  434,    2, 0x08 /* Private */,
      75,    0,  435,    2, 0x08 /* Private */,
      76,    2,  436,    2, 0x08 /* Private */,
      76,    1,  441,    2, 0x28 /* Private | MethodCloned */,
      80,    0,  444,    2, 0x08 /* Private */,
      81,    0,  445,    2, 0x08 /* Private */,
      82,    1,  446,    2, 0x08 /* Private */,
      83,    1,  449,    2, 0x08 /* Private */,
      86,    0,  452,    2, 0x08 /* Private */,
      87,    1,  453,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QColor,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   31,
    QMetaType::Void, QMetaType::Bool,   33,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,   13,
    QMetaType::Void, QMetaType::Bool,   37,
    QMetaType::Void, QMetaType::Bool,   37,
    QMetaType::Void, QMetaType::Bool,   37,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,   42,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   47,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, 0x80000000 | 50,   51,
    QMetaType::Void, QMetaType::QColor,   13,
    QMetaType::Void, QMetaType::Int,   47,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,   13,
    QMetaType::Void, 0x80000000 | 58,   59,
    QMetaType::Void, 0x80000000 | 61,   59,
    QMetaType::Void, QMetaType::QReal,   20,
    QMetaType::Void, 0x80000000 | 64,   42,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,   68,
    QMetaType::Void, QMetaType::QString,   70,
    QMetaType::Void, QMetaType::QSize, QMetaType::QColor,   72,   73,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage, 0x80000000 | 78,   77,   79,
    QMetaType::Void, QMetaType::QImage,   77,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 84,   85,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   88,

       0        // eod
};

void BoardWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BoardWidget *_t = static_cast<BoardWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_open(); break;
        case 1: _t->signal_undo(); break;
        case 2: _t->signal_redo(); break;
        case 3: _t->signal_toolChanged((*reinterpret_cast< tools::Tool::Type(*)>(_a[1]))); break;
        case 4: _t->signal_mouse(); break;
        case 5: _t->signal_brushChange((*reinterpret_cast< tools::Tool::Type(*)>(_a[1]))); break;
        case 6: _t->signal_textsize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->signal_color((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 8: _t->signal_decal(); break;
        case 9: _t->signal_expandup(); break;
        case 10: _t->signal_expandright(); break;
        case 11: _t->signal_expanddown(); break;
        case 12: _t->signal_expandleft(); break;
        case 13: _t->signal_zoom((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 14: _t->signal_zoomin(); break;
        case 15: _t->signal_zoomout(); break;
        case 16: _t->signal_zoomorig(); break;
        case 17: _t->signal_rotateorig(); break;
        case 18: _t->signal_rotatecw(); break;
        case 19: _t->signal_rotateccw(); break;
        case 20: _t->signal_rotate90(); break;
        case 21: _t->signal_rotate180(); break;
        case 22: _t->signal_rotate270(); break;
        case 23: _t->signal_viewflip((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->signal_viewmirror((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->signal_clearArea(); break;
        case 26: _t->signal_fillArea((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 27: _t->signal_showannotations((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->signal_showuserlayers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->signal_showlasers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->operation_open(); break;
        case 31: _t->operation_load((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 32: _t->operation_undo(); break;
        case 33: _t->operation_redo(); break;
        case 34: _t->operation_mouseCheck(); break;
        case 35: _t->operation_pensize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->operation_text((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->operation_shape((*reinterpret_cast< ShapeType(*)>(_a[1]))); break;
        case 38: _t->operation_color((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 39: _t->operation_eraser((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->operation_decal(); break;
        case 41: _t->operation_clearArea(); break;
        case 42: _t->operation_fillArea((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 43: _t->operation_expand((*reinterpret_cast< ExpandDirection(*)>(_a[1]))); break;
        case 44: _t->operation_rotation((*reinterpret_cast< RotationDirecton(*)>(_a[1]))); break;
        case 45: _t->operation_zoom((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 46: _t->operation_save((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 47: _t->operation_screenshots(); break;
        case 48: _t->showNew(); break;
        case 49: _t->open(); break;
        case 50: _t->open((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 51: _t->save((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 52: _t->newDocument((*reinterpret_cast< const QSize(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2]))); break;
        case 53: _t->updateTabletSupportMode(); break;
        case 54: _t->paste(); break;
        case 55: _t->pasteImage((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< const QPoint*(*)>(_a[2]))); break;
        case 56: _t->pasteImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 57: _t->clearOrDelete(); break;
        case 58: _t->resizeCanvas(); break;
        case 59: _t->toolChanged((*reinterpret_cast< tools::Tool::Type(*)>(_a[1]))); break;
        case 60: _t->onCanvasChanged((*reinterpret_cast< canvas::CanvasModel*(*)>(_a[1]))); break;
        case 61: _t->onCanvasSaveStarted(); break;
        case 62: _t->onCanvasSaved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_open)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_undo)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_redo)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)(tools::Tool::Type );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_toolChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_mouse)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)(tools::Tool::Type );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_brushChange)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_textsize)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_color)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_decal)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_expandup)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_expandright)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_expanddown)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_expandleft)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)(qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_zoom)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_zoomin)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_zoomout)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_zoomorig)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_rotateorig)) {
                *result = 17;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_rotatecw)) {
                *result = 18;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_rotateccw)) {
                *result = 19;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_rotate90)) {
                *result = 20;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_rotate180)) {
                *result = 21;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_rotate270)) {
                *result = 22;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_viewflip)) {
                *result = 23;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_viewmirror)) {
                *result = 24;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_clearArea)) {
                *result = 25;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_fillArea)) {
                *result = 26;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_showannotations)) {
                *result = 27;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_showuserlayers)) {
                *result = 28;
                return;
            }
        }
        {
            typedef void (BoardWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoardWidget::signal_showlasers)) {
                *result = 29;
                return;
            }
        }
    }
}

const QMetaObject BoardWidget::staticMetaObject = {
    { &DrawingBoard::staticMetaObject, qt_meta_stringdata_BoardWidget.data,
      qt_meta_data_BoardWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BoardWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BoardWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BoardWidget.stringdata0))
        return static_cast<void*>(const_cast< BoardWidget*>(this));
    return DrawingBoard::qt_metacast(_clname);
}

int BoardWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DrawingBoard::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 63)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 63;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 63)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 63;
    }
    return _id;
}

// SIGNAL 0
void BoardWidget::signal_open()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void BoardWidget::signal_undo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void BoardWidget::signal_redo()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void BoardWidget::signal_toolChanged(tools::Tool::Type _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BoardWidget::signal_mouse()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void BoardWidget::signal_brushChange(tools::Tool::Type _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void BoardWidget::signal_textsize(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void BoardWidget::signal_color(QColor _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void BoardWidget::signal_decal()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void BoardWidget::signal_expandup()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void BoardWidget::signal_expandright()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void BoardWidget::signal_expanddown()
{
    QMetaObject::activate(this, &staticMetaObject, 11, Q_NULLPTR);
}

// SIGNAL 12
void BoardWidget::signal_expandleft()
{
    QMetaObject::activate(this, &staticMetaObject, 12, Q_NULLPTR);
}

// SIGNAL 13
void BoardWidget::signal_zoom(qreal _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void BoardWidget::signal_zoomin()
{
    QMetaObject::activate(this, &staticMetaObject, 14, Q_NULLPTR);
}

// SIGNAL 15
void BoardWidget::signal_zoomout()
{
    QMetaObject::activate(this, &staticMetaObject, 15, Q_NULLPTR);
}

// SIGNAL 16
void BoardWidget::signal_zoomorig()
{
    QMetaObject::activate(this, &staticMetaObject, 16, Q_NULLPTR);
}

// SIGNAL 17
void BoardWidget::signal_rotateorig()
{
    QMetaObject::activate(this, &staticMetaObject, 17, Q_NULLPTR);
}

// SIGNAL 18
void BoardWidget::signal_rotatecw()
{
    QMetaObject::activate(this, &staticMetaObject, 18, Q_NULLPTR);
}

// SIGNAL 19
void BoardWidget::signal_rotateccw()
{
    QMetaObject::activate(this, &staticMetaObject, 19, Q_NULLPTR);
}

// SIGNAL 20
void BoardWidget::signal_rotate90()
{
    QMetaObject::activate(this, &staticMetaObject, 20, Q_NULLPTR);
}

// SIGNAL 21
void BoardWidget::signal_rotate180()
{
    QMetaObject::activate(this, &staticMetaObject, 21, Q_NULLPTR);
}

// SIGNAL 22
void BoardWidget::signal_rotate270()
{
    QMetaObject::activate(this, &staticMetaObject, 22, Q_NULLPTR);
}

// SIGNAL 23
void BoardWidget::signal_viewflip(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void BoardWidget::signal_viewmirror(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void BoardWidget::signal_clearArea()
{
    QMetaObject::activate(this, &staticMetaObject, 25, Q_NULLPTR);
}

// SIGNAL 26
void BoardWidget::signal_fillArea(QColor _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void BoardWidget::signal_showannotations(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void BoardWidget::signal_showuserlayers(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void BoardWidget::signal_showlasers(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}
QT_END_MOC_NAMESPACE
