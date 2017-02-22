/****************************************************************************
** Meta object code from reading C++ file 'moviesgui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../moviesgui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'moviesgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MoviesGUI_t {
    QByteArrayData data[22];
    char stringdata0[273];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MoviesGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MoviesGUI_t qt_meta_stringdata_MoviesGUI = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MoviesGUI"
QT_MOC_LITERAL(1, 10, 15), // "movieListChange"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "watchListChange"
QT_MOC_LITERAL(4, 43, 14), // "addMovieSignal"
QT_MOC_LITERAL(5, 58, 11), // "std::string"
QT_MOC_LITERAL(6, 70, 5), // "title"
QT_MOC_LITERAL(7, 76, 5), // "genre"
QT_MOC_LITERAL(8, 82, 4), // "link"
QT_MOC_LITERAL(9, 87, 4), // "year"
QT_MOC_LITERAL(10, 92, 5), // "likes"
QT_MOC_LITERAL(11, 98, 10), // "populateML"
QT_MOC_LITERAL(12, 109, 10), // "populateWL"
QT_MOC_LITERAL(13, 120, 16), // "addButtonHandler"
QT_MOC_LITERAL(14, 137, 19), // "removeButtonHandler"
QT_MOC_LITERAL(15, 157, 19), // "updateButtonHandler"
QT_MOC_LITERAL(16, 177, 19), // "filterButtonHandler"
QT_MOC_LITERAL(17, 197, 17), // "likeButtonHandler"
QT_MOC_LITERAL(18, 215, 17), // "playButtonHandler"
QT_MOC_LITERAL(19, 233, 21), // "addWatchButtonHandler"
QT_MOC_LITERAL(20, 255, 8), // "showInfo"
QT_MOC_LITERAL(21, 264, 8) // "addMovie"

    },
    "MoviesGUI\0movieListChange\0\0watchListChange\0"
    "addMovieSignal\0std::string\0title\0genre\0"
    "link\0year\0likes\0populateML\0populateWL\0"
    "addButtonHandler\0removeButtonHandler\0"
    "updateButtonHandler\0filterButtonHandler\0"
    "likeButtonHandler\0playButtonHandler\0"
    "addWatchButtonHandler\0showInfo\0addMovie"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MoviesGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    5,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   97,    2, 0x0a /* Public */,
      12,    0,   98,    2, 0x0a /* Public */,
      13,    0,   99,    2, 0x0a /* Public */,
      14,    0,  100,    2, 0x0a /* Public */,
      15,    0,  101,    2, 0x0a /* Public */,
      16,    0,  102,    2, 0x0a /* Public */,
      17,    0,  103,    2, 0x0a /* Public */,
      18,    0,  104,    2, 0x0a /* Public */,
      19,    0,  105,    2, 0x0a /* Public */,
      20,    0,  106,    2, 0x0a /* Public */,
      21,    5,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, QMetaType::Int, QMetaType::Int,    6,    7,    8,    9,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, QMetaType::Int, QMetaType::Int,    6,    7,    8,    9,   10,

       0        // eod
};

void MoviesGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MoviesGUI *_t = static_cast<MoviesGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->movieListChange(); break;
        case 1: _t->watchListChange(); break;
        case 2: _t->addMovieSignal((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< std::string(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 3: _t->populateML(); break;
        case 4: _t->populateWL(); break;
        case 5: _t->addButtonHandler(); break;
        case 6: _t->removeButtonHandler(); break;
        case 7: _t->updateButtonHandler(); break;
        case 8: _t->filterButtonHandler(); break;
        case 9: _t->likeButtonHandler(); break;
        case 10: _t->playButtonHandler(); break;
        case 11: _t->addWatchButtonHandler(); break;
        case 12: _t->showInfo(); break;
        case 13: _t->addMovie((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< std::string(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MoviesGUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MoviesGUI::movieListChange)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MoviesGUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MoviesGUI::watchListChange)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MoviesGUI::*_t)(std::string , std::string , std::string , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MoviesGUI::addMovieSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MoviesGUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MoviesGUI.data,
      qt_meta_data_MoviesGUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MoviesGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MoviesGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MoviesGUI.stringdata0))
        return static_cast<void*>(const_cast< MoviesGUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int MoviesGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MoviesGUI::movieListChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MoviesGUI::watchListChange()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MoviesGUI::addMovieSignal(std::string _t1, std::string _t2, std::string _t3, int _t4, int _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
