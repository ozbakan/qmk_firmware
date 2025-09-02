# Dev Notes — crkbd rev4.1 (ozbakan)

Quick reference for building, flashing, cabling, and usage on macOS.

## What this is
- Board: Corne (CRKBD) rev4.1 standard, RP2040 (manufacturer: foostan)
- VID/PID: 0x4653 / 0x0004
- Keymap: `ozbakan`
- Layout diagrams: see `README.md` in this folder

## Build
- Prereq: QMK CLI installed and working (`qmk --version`, `qmk doctor`).
- Build UF2:
  - `qmk compile -kb crkbd/rev4_1/standard -km ozbakan`
  - Output: `.build/crkbd_rev4_1_standard_ozbakan.uf2` (also copied to repo root)

## Flash (each half separately)
1) Unplug the TRRS cable between halves.
2) Pick one half. Leave the other half COMPLETELY unplugged.
3) Enter bootloader on that half (any one works):
   - Hold the “Q” key (left) or “P” key (right) while plugging in USB, or
   - Double‑tap reset pads/button quickly (RP2040 double‑tap), or
   - Hold BOOTSEL (if present) while plugging in USB.
   - A drive named `RPI-RP2` appears.
4) Copy firmware: drag `crkbd_rev4_1_standard_ozbakan.uf2` onto `RPI-RP2`.
   - macOS warning “Disk not ejected properly” is normal — the board reboots itself.
5) Unplug that half.
6) Repeat steps 2–4 for the other half.
7) Reconnect TRRS firmly on both halves. Plug USB into the half you want as master; leave the other half’s USB unplugged.

## Cables & power
- Use a straight‑through TRRS (or TRS) cable; avoid inline remotes/mics.
- Seat both ends fully.
- Only one USB cable connected during normal use (on the master half).

## Layout essentials
- Thumbs:
  - Left: `[ Ctrl | MO(1) Numbers | LT(2, Esc) ]` (tap = Esc, hold = Symbols)
- Right: `[ Enter | Space | RGUI ]`
- Layer 1 (Numbers): hold left‑center `MO(1)` for `1–0`; arrows on right home row.
- Layer 2 (Symbols + Mac controls): hold left‑inner `LT(2, Esc)`.
  - Left middle row: `MUTE`, `VOLD`, `VOLU`, `~`
  - Left bottom row: `Ctl+Sp` (input source), `F14`, `F15`, `` ` ``
  - Right: `-` and `+` side‑by‑side; `_` under `-`; `=` under `+`; `{ } |` nearby.
- Two Shifts: bottom corners (left and right) on all layers.

## macOS settings
- Input source switching: System Settings → Keyboard → Keyboard Shortcuts → Input Sources → set “Select the previous input source” to `Control + Space`.
- Brightness: external displays via `F14/F15` (configure MonitorControl to use these). Built‑in display uses macOS’ native brightness keys.

## Troubleshooting
- Half doesn’t show `RPI-RP2`: try a different USB cable/port; re‑try Q/P hold or double‑tap reset.
- After copy, keyboard doesn’t come back: re‑enter bootloader and copy again.
- One half not typing: reseat TRRS both ends; ensure both halves flashed the SAME UF2; USB into intended master only.
- Esc vs Symbols timing feels off: increase `TAPPING_TERM` slightly (e.g., 200–220ms) or add per‑key tuning later.

## Handy commands
- Compile: `qmk compile -kb crkbd/rev4_1/standard -km ozbakan`
- Clean (optional): `qmk clean`
- Show QMK info: `qmk info -kb crkbd/rev4_1/standard -km ozbakan`

---
Keep this file and `README.md` in sync if you change the layout.
