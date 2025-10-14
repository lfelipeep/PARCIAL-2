# Sistema de Citas  Explicación paso a paso
Este proyecto es un programa hecho en C++ que sirve para registrar, consultar, cancelar y ver citas médicas, pero con una regla especial: solo se pueden usar variables primitivas, sin arreglos ni listas. 

# Qué hace el programa
Este sistema permite manejar hasta 3 citas médicas. Cada cita guarda:

Nombre del paciente 

Fecha 

Hora 

Motivo 

Tiene un menú principal donde puedes:

Registrar una cita nueva.

Consultar las citas de un día específico.

Cancelar una cita por nombre y fecha.

Ver todas las citas registradas (historial).

Salir del sistema.

Todo se guarda usando solo variables normales, sin estructuras ni listas.

#Paso a paso del código

**1) Variables iniciales
Se crean las variables para cada una de las 3 posibles citas:
```
string nom1, fec1, hor1, mot1;
string nom2, fec2, hor2, mot2;
string nom3, fec3, hor3, mot3;
```
Cada grupo representa una cita diferente (1, 2 y 3). Así evitamos usar arreglos.

2) Menú principal
El programa se repite en un do...while, mostrando un menú con 5 opciones.
```
cout << "1. Agendar nueva cita";
cout << "2. Ver citas por fecha";
cout << "3. Cancelar cita";
cout << "4. Historial de pacientes";
cout << "5. Salir";
```
El usuario elige un número y el programa actúa según la opción.

3) Registrar una nueva cita
Cuando el usuario elige 1, se busca un espacio vacío:
```
if (nom1.empty()) {...}
else if (nom2.empty()) {...}
else if (nom3.empty()) {...}
```
Si hay espacio, se piden los datos y se guardan usando punteros (*nom, *fec, etc.) para escribir en la cita libre. Si las 3 están ocupadas, se muestra que no hay espacio.

4) Ver citas por fecha
Cuando se elige 2, el programa pide una fecha y busca coincidencias:
```auto mostrar = [&](string n, string f, string h, string m, int pos) {...};```
Usa una función corta (lambda) para no repetir tanto código. Muestra solo las citas que tienen la misma fecha.
Si no encuentra ninguna, dice: No hay citas programadas para esa fecha.

5) Cancelar una cita
Opción 3. Se pide el nombre y la fecha, y si hay una coincidencia:
```
no = fe = ho = mo = "";
```
Todo se borra (queda vacío). Así se cumple el requisito de “dejar los valores en cero o vacíos”.
Si no encuentra esa cita, avisa al usuario.

6) Ver historial de pacientes
Opción 4. Muestra todas las citas que no están vacías:
```
if (!n.empty()) {...}
```
Si no hay ninguna, dice No hay pacientes registrados.
Esto sirve como el historial de pacientes atendidos o registrados.

7) Salir del sistema
Opción 5 termina el programa con un mensaje:
```
cout << "Saliendo del sistema...";
```
El bucle do while se detiene.
