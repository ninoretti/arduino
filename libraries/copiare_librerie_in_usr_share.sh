#
# Copiare le librerie directory /usr/share/arduino/libraries
# Cambiare il carattere "-" non è ammesso nel nominare le directory
#
#!/bin/bash

sudo cp -R * /usr/share/arduino/libraries
sudo chmod -R 755 /usr/share/arduino/libraries

