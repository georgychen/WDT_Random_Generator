# WDT_Random_Generator
A random nuber generator for arduino, especially targeted for program startup.

This is an arduino library to create random numbers. It uses WDT (watch dog timer) and timer 0 to create a 8-bit number each time the getWdtRandom() function is called.

The default iteration setting is 24, and wdt interrupt period is 16ms, thus it takes around 24 * 16 = 384ms for each output. While the output rate is very low, it can be used as a random seed during program startup. It is very unlikely to get same initial number(s) upon arduino resets.

No hardware (analog) pins required, however, watch dog timer is reset after function call. User needs special care if WDT is used otherwise.

Inspired by:

-Arduino hardware true random number generator   https://gist.github.com/endolith/2568571
