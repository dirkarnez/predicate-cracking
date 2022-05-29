predicate-cracking
==================
### Notes
1. Find the address to overwrite (e.g. "x64dbg.exe"), this address may be changed for each (re)compilation:
  ```
  00000000004015F2 | 74 24                    | je predicate-cracking.401618            |
  ```
2. copy `00000000004015F2` to `cracker/bb.py`
3. replace this `je bla bla bla` instruction with 2 `nop` instructions (same size)
4. This works because the program is waiting for user input (blocking), the patching can be done

### Reference
- [JavaScript API | Frida • A world-class dynamic instrumentation framework](https://frida.re/docs/javascript-api/)
- [Windows | Frida • A world-class dynamic instrumentation framework](https://frida.re/docs/examples/windows/)
- [**iddoeldor/frida-snippets: Hand-crafted Frida examples**](https://github.com/iddoeldor/frida-snippets#intercept-entire-module)