/****************************************************************************
** Meta object code from reading C++ file 'document.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../document.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'document.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Document_t {
    QByteArrayData data[50];
    char stringdata0[574];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Document_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Document_t qt_meta_stringdata_Document = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Document"
QT_MOC_LITERAL(1, 9, 13), // "canvasChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 20), // "canvas::CanvasModel*"
QT_MOC_LITERAL(4, 45, 6), // "canvas"
QT_MOC_LITERAL(5, 52, 11), // "dirtyCanvas"
QT_MOC_LITERAL(6, 64, 7), // "isDiaty"
QT_MOC_LITERAL(7, 72, 15), // "autosaveChanged"
QT_MOC_LITERAL(8, 88, 8), // "autosave"
QT_MOC_LITERAL(9, 97, 18), // "cnaAutosaveChanged"
QT_MOC_LITERAL(10, 116, 11), // "canAutosave"
QT_MOC_LITERAL(11, 128, 22), // "currentFilenameChanged"
QT_MOC_LITERAL(12, 151, 8), // "filename"
QT_MOC_LITERAL(13, 160, 17), // "autoResetTooLarge"
QT_MOC_LITERAL(14, 178, 7), // "maxSize"
QT_MOC_LITERAL(15, 186, 15), // "catchupProgress"
QT_MOC_LITERAL(16, 202, 6), // "perent"
QT_MOC_LITERAL(17, 209, 17), // "canvasSaveStarted"
QT_MOC_LITERAL(18, 227, 11), // "canvasSaved"
QT_MOC_LITERAL(19, 239, 12), // "errorMessage"
QT_MOC_LITERAL(20, 252, 15), // "sendPointerMove"
QT_MOC_LITERAL(21, 268, 5), // "point"
QT_MOC_LITERAL(22, 274, 16), // "sendResizeCanvas"
QT_MOC_LITERAL(23, 291, 3), // "top"
QT_MOC_LITERAL(24, 295, 5), // "right"
QT_MOC_LITERAL(25, 301, 6), // "bottom"
QT_MOC_LITERAL(26, 308, 4), // "left"
QT_MOC_LITERAL(27, 313, 4), // "undo"
QT_MOC_LITERAL(28, 318, 4), // "redo"
QT_MOC_LITERAL(29, 323, 9), // "selectAll"
QT_MOC_LITERAL(30, 333, 10), // "selectNone"
QT_MOC_LITERAL(31, 344, 15), // "cancelSelection"
QT_MOC_LITERAL(32, 360, 11), // "copyVisible"
QT_MOC_LITERAL(33, 372, 9), // "copyLayer"
QT_MOC_LITERAL(34, 382, 8), // "cutLayer"
QT_MOC_LITERAL(35, 391, 10), // "pasteImage"
QT_MOC_LITERAL(36, 402, 5), // "image"
QT_MOC_LITERAL(37, 408, 10), // "forcePoint"
QT_MOC_LITERAL(38, 419, 5), // "stamp"
QT_MOC_LITERAL(39, 425, 22), // "removeEmptyAnnotations"
QT_MOC_LITERAL(40, 448, 8), // "fillArea"
QT_MOC_LITERAL(41, 457, 5), // "color"
QT_MOC_LITERAL(42, 463, 26), // "paintcore::BlendMode::Mode"
QT_MOC_LITERAL(43, 490, 4), // "mode"
QT_MOC_LITERAL(44, 495, 14), // "snapshotNeeded"
QT_MOC_LITERAL(45, 510, 9), // "markDirty"
QT_MOC_LITERAL(46, 520, 11), // "unmarkDirty"
QT_MOC_LITERAL(47, 532, 11), // "autosaveNow"
QT_MOC_LITERAL(48, 544, 13), // "onCanvasSaved"
QT_MOC_LITERAL(49, 558, 15) // "currentFilename"

    },
    "Document\0canvasChanged\0\0canvas::CanvasModel*\0"
    "canvas\0dirtyCanvas\0isDiaty\0autosaveChanged\0"
    "autosave\0cnaAutosaveChanged\0canAutosave\0"
    "currentFilenameChanged\0filename\0"
    "autoResetTooLarge\0maxSize\0catchupProgress\0"
    "perent\0canvasSaveStarted\0canvasSaved\0"
    "errorMessage\0sendPointerMove\0point\0"
    "sendResizeCanvas\0top\0right\0bottom\0"
    "left\0undo\0redo\0selectAll\0selectNone\0"
    "cancelSelection\0copyVisible\0copyLayer\0"
    "cutLayer\0pasteImage\0image\0forcePoint\0"
    "stamp\0removeEmptyAnnotations\0fillArea\0"
    "color\0paintcore::BlendMode::Mode\0mode\0"
    "snapshotNeeded\0markDirty\0unmarkDirty\0"
    "autosaveNow\0onCanvasSaved\0currentFilename"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Document[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       2,  220, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  154,    2, 0x06 /* Public */,
       5,    1,  157,    2, 0x06 /* Public */,
       7,    1,  160,    2, 0x06 /* Public */,
       9,    1,  163,    2, 0x06 /* Public */,
      11,    1,  166,    2, 0x06 /* Public */,
      13,    1,  169,    2, 0x06 /* Public */,
      15,    1,  172,    2, 0x06 /* Public */,
      17,    0,  175,    2, 0x06 /* Public */,
      18,    1,  176,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    1,  179,    2, 0x0a /* Public */,
      22,    4,  182,    2, 0x0a /* Public */,
      27,    0,  191,    2, 0x0a /* Public */,
      28,    0,  192,    2, 0x0a /* Public */,
      29,    0,  193,    2, 0x0a /* Public */,
      30,    0,  194,    2, 0x0a /* Public */,
      31,    0,  195,    2, 0x0a /* Public */,
      32,    0,  196,    2, 0x0a /* Public */,
      33,    0,  197,    2, 0x0a /* Public */,
      34,    0,  198,    2, 0x0a /* Public */,
      35,    3,  199,    2, 0x0a /* Public */,
      38,    0,  206,    2, 0x0a /* Public */,
      39,    0,  207,    2, 0x0a /* Public */,
      40,    2,  208,    2, 0x0a /* Public */,
      44,    0,  213,    2, 0x08 /* Private */,
      45,    0,  214,    2, 0x08 /* Private */,
      46,    0,  215,    2, 0x08 /* Private */,
      47,    0,  216,    2, 0x08 /* Private */,
      48,    1,  217,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   23,   24,   25,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage, QMetaType::QPoint, QMetaType::Bool,   36,   21,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor, 0x80000000 | 42,   41,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,

 // properties: name, type, flags
       4, 0x80000000 | 3, 0x00495009,
      49, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       4,

       0        // eod
};

void Document::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Document *_t = static_cast<Document *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->canvasChanged((*reinterpret_cast< canvas::CanvasModel*(*)>(_a[1]))); break;
        case 1: _t->dirtyCanvas((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->autosaveChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->cnaAutosaveChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->currentFilenameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->autoResetTooLarge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->catchupProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->canvasSaveStarted(); break;
        case 8: _t->canvasSaved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->sendPointerMove((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 10: _t->sendResizeCanvas((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 11: _t->undo(); break;
        case 12: _t->redo(); break;
        case 13: _t->selectAll(); break;
        case 14: _t->selectNone(); break;
        case 15: _t->cancelSelection(); break;
        case 16: _t->copyVisible(); break;
        case 17: _t->copyLayer(); break;
        case 18: _t->cutLayer(); break;
        case 19: _t->pasteImage((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 20: _t->stamp(); break;
        case 21: _t->removeEmptyAnnotations(); break;
        case 22: _t->fillArea((*reinterpret_cast< const QColor(*)>(_a[1])),(*reinterpret_cast< paintcore::BlendMode::Mode(*)>(_a[2]))); break;
        case 23: _t->snapshotNeeded(); break;
        case 24: _t->markDirty(); break;
        case 25: _t->unmarkDirty(); break;
        case 26: _t->autosaveNow(); break;
        case 27: _t->onCanvasSaved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Document::*_t)(canvas::CanvasModel * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Document::canvasChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Document::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Document::dirtyCanvas)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Document::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Document::autosaveChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Document::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Document::cnaAutosaveChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Document::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Document::currentFilenameChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Document::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Document::autoResetTooLarge)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Document::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Document::catchupProgress)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Document::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Document::canvasSaveStarted)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Document::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Document::canvasSaved)) {
                *result = 8;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Document *_t = static_cast<Document *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< canvas::CanvasModel**>(_v) = _t->canvas(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->currentFilename(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Document::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Document.data,
      qt_meta_data_Document,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Document::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Document::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Document.stringdata0))
        return static_cast<void*>(const_cast< Document*>(this));
    return QObject::qt_metacast(_clname);
}

int Document::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 28;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Document::canvasChanged(canvas::CanvasModel * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Document::dirtyCanvas(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Document::autosaveChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Document::cnaAutosaveChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Document::currentFilenameChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Document::autoResetTooLarge(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Document::catchupProgress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Document::canvasSaveStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void Document::canvasSaved(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
