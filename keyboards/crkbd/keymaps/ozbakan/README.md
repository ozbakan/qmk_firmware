# ozbakan Corne (crkbd) Layout Reference

This document captures the current proposal for your keymap so you can quickly look it up. It does not change firmware by itself.

Access
- Numbers: hold `MO(1)` on left-center thumb.
- Symbols + Mac controls: hold `LT(2, Esc)` on left-inner thumb (tap = `Esc`).

Thumbs
- Left thumbs (Outer | Center | Inner): `[ Ctrl | MO(1) | LT(2, Esc) ]`
- Right thumbs (Inner | Center | Outer): `[ Enter | Space | RGUI ]`

Legend
- `MO(n)`: hold to momentarily access layer `n`.
- `LT(n, key)`: tap = `key`, hold = layer `n`.
- `Ctl+Sp`: Control + Space (macOS input source switch).
- `MUTE`, `VOLD`, `VOLU`, `BRID`, `BRIU`: audio mute, volume down/up, brightness down/up.
- `·`: no special mapping (transparent/unused here).

```
Base (Layer 0)
[ Tab   Q   W   E   R   T ]   [ Y    U    I    O    P    Bspc ]
[ Ctrl  A   S   D   F   G ]   [ H    J    K    L    ;    '    ]
[ Shift Z   X   C   V   B ]   [ N    M    ,    .    /    Shift ]
Left thumbs  (Outer | Center | Inner): [ Ctrl | MO(1)     | LT(2, Esc) ]
Right thumbs (Inner | Center | Outer): [ Enter | Space    | RGUI       ]

Layer 1 — Numbers (MO(1), hold)
[ Tab   1   2   3   4   5 ]   [ 6    7    8    9    0    Bspc ]
[ Ctrl  ·   ·   ·   ·   · ]   [ ←    ↓    ↑    →    ·    ·    ]
[ Shift ·   ·   ·   ·   · ]   [ ·    ·    ·    ·    ·    Shift ]
Thumbs: same as base

Layer 2 — Symbols + Mac controls (hold via LT(2, Esc))
[ Tab   !    @    #    $    % ]   [ ^    &    *    (    )    Bspc ]
[ Ctrl  ·    MUTE  VOLD VOLU  ~ ]   [ -    +    [    ]    \\    ·   ]
[ Shift ·   Ctl+Sp F14  F15   ` ]   [ _    =    {    }    |    Shift ]
```

Notes
- Esc on left inner thumb: tap sends `Esc`; hold engages Layer 2. If the layer triggers when you want `Esc`, we can raise `TAPPING_TERM` slightly (e.g., 200–220ms) or per-key tune later.
- Brightness: For external displays, keys send `F14/F15` (use MonitorControl or similar to map these to brightness). For built-in laptop display, use the system brightness keys.
- Input source switching on macOS: ensure System Settings → Keyboard → Keyboard Shortcuts → Input Sources → “Select the previous input source” is bound to `Control + Space`.
