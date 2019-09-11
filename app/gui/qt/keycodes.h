#ifndef KEYCODES_H
#define KEYCODES_H

#ifdef Q_OS_MAC
    #define SP_CTRL "Meta+%1"
    #define SP_META "Ctrl+%1"
    #define SP_SHIFTMETA "Shift+Ctrl+%1"
    #define SP_CTRLMETA "Ctrl+Meta+%1"
    #define SP_CTRLSHIFTMETA "Shift+Ctrl+Meta+%1"
    #define TOOLTIP_STRSHIFTMETA "%1 (⇧⌘%2)"
    #define TOOLTIP_STRMETA "%1 (⌘%2)"
#else
    #define SP_CTRL "Ctrl+%1"
    #define SP_META "Alt+%1"
    #define SP_SHIFTMETA "Shift+Alt+%1"
    #define SP_CTRLMETA "Ctrl+Alt+%1"
    #define SP_CTRLSHIFTMETA "Shift+Ctrl+Alt+%1"
    #define TOOLTIP_STRSHIFTMETA "%1 (Shift-alt-%2)"
    #define TOOLTIP_STRMETA "%1 (alt-%2)"
#endif

#endif
