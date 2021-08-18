# Crosscompiling x86_64 -> arm
# Requisitos
- compilador: arm-linux-gnueabi
    Puede ser instalado con el siguiente comando:
    - Ubuntu/Debian based
    **sudo apt-get update**
    **sudo apt install -y build-essential gcc-arm-linux-gnueabi**
- Libreria para el manejo de GPIO en C: **pigpio**
    Para instrucciones de instalación vaya a:
    **https://abyz.me.uk/rpi/pigpio/download.html**
    - Una vez instalada la libreria, se debe borrar el directorio, volver a descomprimir y seguir las indicaciones siguientes:
    - **MODIFICACIÓN NECESARIA PARA COMPILAR EN ARM**
    - una vez descomprimido el master.zip(de preferencia en el directorio de tu proyecto) deberás modificar el archivo llamado MakeFile en un editor de texto: agregando a la siguiente linea lo que ves a continuación.
    (default)CROSS_PREFIX =
    ->
    (después)CROSS_PREFIX = arm-linux-gnueabi-
    - una vez modificado, guardamos y en el mismo directorio escribimos "make"(sin comillas) y posteriormente cuando este proceso acabe escribiremos "sudo make install" para que el instalador en python corra el proceso.
    - **DESCONOZCO SI ESTE ES EL PROCEDIMIENTO CORRECTO, PERO ES LA FORMA EN QUE HE CONSEGUIDO HACERLO**

- Raspberry pi 3 model B+ **(Debería funcionar de manera analoga con otro modelo)**
- LED
# Instrucciones
1. Escribe o descarga algunos de los programas de ejemplo en este repositorio:
    - hello.c
    - blink.c
    - secuencias.c
2. Modifica el mapeo de gpio->pin a tu circuito.
    Para ver el mapeo gpio->pin de la libreria pigpio vaya a: **https://abyz.me.uk/rpi/pigpio/index.html**
3. compila el programa .c con el siguiente comando en el directorio donde se encuentre el archivo:
    - arm-linux-gnueabi-gcc -Wall -pthread -L/home/isur/Documents/Git/Crosscompiling-VSCODE/pigpio-master -I/home/isur/Documents/Git/Crosscompiling-VSCODE/pigpio-master -o "blink_arm" blink.c -lpigpio -lrt
    **RECUERDA QUE LAS RUTAS DE ARCHIVO DESCRITAS ANTES SOLO CORRESPONDEN A MI DIRECTORIO, DEBES INGRESAR LAS RUTAS DE ARCHIVO QUE APUNTEN HACÍA LA LIBRERÍA QUE INSTALASTE.**
4. Subelo a tu repositorio y descargalo en tu raspberry pi.
5. corre el ejecutable con **sudo ./blink_arm**
