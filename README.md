# Marlin 3D Printer Firmware (Legacy)

<img align="top" width=175 src="buildroot/share/pixmaps/logo/marlin-250.png" />

Additional documentation can be found at the [Marlin Home Page](http://marlinfw.org/).
Please test this firmware and let us know if it misbehaves in any way. Volunteers are standing by!

## Bugfix Branch

__Not for production use. Use with caution!__

This branch is used to accumulate patches to the latest 1.1.x release version. Periodically this branch will form the basis for the next minor 1.1.x release.

Download earlier versions of Marlin on the [Releases page](https://github.com/MarlinFirmware/Marlin/releases). (The latest tagged release of Marlin is version 1.1.9.)

## Upcoming Changes
- Hardware SPI support for SSD1306 displays
- Bundled "vendor copy" U8glib

## Recent Changes
- Fix hotend temperature changes from LCD UI not being applied to PID controller
- Fix compiler warnings about certain boards not having hardware timers for certain fan pins.
- Internally always use native machine space
- Initial UBL LCD Menu
- New optimized G-code parser singleton
- Initial `M3`/`M4`/`M5` Spindle and Laser support
- Added `M421 Q` to offset a mesh point
- Refinements to `G26` and `G33`
- Added `M80 S` to query the power state
- "Cancel Print" now shuts off heaters
- Added `EXTRAPOLATE_BEYOND_GRID` option for mesh-based leveling

## Submitting Patches

Proposed patches should be submitted as a Pull Request against this branch ([bugfix-1.1.x](https://github.com/CDRXavier/Marlin_1_X_Legacy)).

- This branch is for fixing bugs and integrating any new features for the duration of the Marlin 1.1.x life-cycle. We've opted for a simplified branch structure while we work on the maintainability and encapsulation of code modules.
- Follow the proper coding style to gain points with the maintainers. See our [Coding Standards](http://marlinfw.org/docs/development/coding_standards.html) page for more information.
- Please submit your questions and concerns to the [Issue Queue](https://github.com/CDRXavier/Marlin_1_X_Legacy/issues). The "naive" question is often the one we forget to ask.

### [RepRap.org Wiki Page](http://reprap.org/wiki/Marlin)

## Credits

The current Marlin dev team can be found on the [main MarlinFirmware repository](https://github.com/MarlinFirmware/Marlin). This branch includes changes implemented by me as bugfix or enhancements.

## License

Marlin is published under the [GPL license](/LICENSE) because we believe in open development. The GPL comes with both rights and obligations. Whether you use Marlin firmware as the driver for your open or closed-source product, you must keep Marlin open, and you must provide your compatible Marlin source code to end users upon request. The most straightforward way to comply with the Marlin license is to make a fork of Marlin on Github, perform your modifications, and direct users to your modified fork.

While we can't prevent the use of this code in products (3D printers, CNC, etc.) that are closed source or crippled by a patent, we would prefer that you choose another firmware or, better yet, make your own.
