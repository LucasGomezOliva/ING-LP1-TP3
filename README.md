# ING-LP1-TP3

1. Modelizar UML de las clases pedidas con sus relaciones.
2. Generar los archivos pedidos de las clases que considere necesarias e implementar
un main con las características mencionadas al final del archivo.
3. Generar los métodos to_string e Imprimir en pantalla para cada clase, ninguna debe
recibir nada por parámetro y devuelve los atributos concatenados como un string
4. Generar los getters y setters que crea necesarios!!

El INCUCAI (Instituto Nacional Central Único Coordinador de Ablación e Implante) se
encarga de la coordinación y logística de la donación de tejidos y órganos. Debido a que su
sistema quedó desactualizado por el paso del tiempo, le solicitaron realizar una nueva
versión dónde tendrá que mejorar la automatización y la logística para optimizar la llegada
de órganos a los pacientes que se encuentran en la lista de espera. Este consta de una lista
de receptores, una lista de donantes y una lista de centros de salud habilitados.

Los Pacientes poseen nombre, fecha de nacimiento, sexo, teléfono de contacto, tipo de
sangre, y centro de salud asociado. Los pacientes (Clase Abstracta) se pueden dividir en
Receptores y Donantes.

El Donante posee la fecha y hora de fallecimiento, fecha y hora del comienzo de ablación y
listado de órganos a donar.

El Receptor contiene órgano que va a recibir (uno solo) fecha que fue agregado a la lista de
espera, prioridad, patología y estado (Estable o Inestable).
Los órganos que se pueden donar son los siguientes: corazón, hígado, páncreas, huesos,
riñón, pulmones, intestino, piel y córneas. Además, órganos almacenan la fecha y hora de
ablación (si todavía no corresponde esta se mantiene en NULL).

El INCUCAI tiene un método RecibirPaciente. Este método recibe al Paciente, y llama al
método IngresarPaciente. Si el paciente es donante, este método recibe al paciente donante
y lo agrega a la lista de pacientes donantes. Luego el instituto Busca los Posibles
Receptores (este método devuelve una sublista) para cada órgano que el Donante puede
donar, para esto busca en su lista de pacientes receptores todos los pacientes que
necesitan ese órgano y tienen el mismo tipo de sangre. Finalmente, Elige el Receptor, en
función a la prioridad del paciente (si tienen la misma prioridad elige al que tiene una fecha
anterior de ingreso a la lista de espera). Si el paciente es receptor, se lo agrega a la lista de
pacientes receptores, y se busca si hay alguna coincidencia en la lista de donantes. En
ambos casos, el método devuelve el puntero de tipo cPaciente que corresponde al match,
en caso de que no encuentre un match, devuelve un puntero NULL.

Acerca de los Centros de Salud estos tienen los siguientes datos: Nombre, Dirección,
Partido, Provincia, Teléfono y una lista de vehículos. Los centros de salud asignan un
vehiculo para el transporte del órgano. Esta selección de vehículos se realiza en base a la
distancia. Si se encuentra en la misma provincia y partido, se debe hacer uso de una
Ambulancia. Si se encuentra en la misma provincia, pero en un partido distinto, se utiliza el
Helicóptero. Si discierne la provincia se utiliza el Avión.

Una vez que el INCUCAI encontró un match, Inicia el Protocolo de Transporte y Trasplante.
Este le pide al centro de salud del donante que Asigne un Vehículo. Una vez que se asignó
el Vehículo, el centro procede a realizar la ablación del órgano que necesita el receptor. En
la ablación se setea la fecha y horario de ablación del órgano y se quita el órgano removido
de la lista de órganos del paciente donante. Ese vehículo Realiza el Transporte. Finalmente,
el centro de salud del receptor realiza el trasplante. Para realizar el trasplante se verifica
que no hayan transcurrido más de 20 horas desde la ablación del órgano y procede a
realizar el trasplante. Si el trasplante es exitoso, se remueve al paciente receptor de la lista
de pacientes receptores. Si el trasplante falla, se cambia la prioridad del paciente receptor a
la mayor prioridad y se setea su estado a inestable. Si el trasplante es exitoso o no se
define con un random equiprobable.

Los vehículos Realizan en Transporte de los órganos de diferentes maneras. La Ambulancia
imprime “iuiuiuiuiu” y “La ambulancia llegó a destino”, el Helicóptero imprime
“taca-taca-taca” y “El helicóptero llegó a destino”, y el Avión imprime “zhooooooom” y “El
avión llegó a destino”.

Se requiere el uso de la librería ctime.

El Sistema tiene que permitir:
● Agregar pacientes (Verificar que no se encuentre en otra lista ni se repita).
● Buscar por órgano/centro de salud los pacientes de la lista de espera.
● Buscar un Receptor e informar en qué prioridad tiene en la lista de espera.
● Imprimir listado de pacientes donantes y receptores.
● Informar al fin de cada mes, cuántas donaciones se realizaron en cada provincia.

Usar sobrecarga + para añadir y - quitar elementos de las listas.

Usar sobrecarga == para verificar si el Donante es compatible con el receptor.

Usar sobrecarga [] para acceder a las distintas posiciones de las listas.

Usar sobrecarga de operador ostream para imprimir las listas.

Utilizar como mínimo un dynamic cast y un método virtual (que no sea un getter).

IMPORTANTE, Esta consigna es la base de lo que necesitan hacer, cualquier cosa extra es
bienvenida o si les interesa agregar algún concepto que hayan visto en algún lado pueden
hacerlo, en caso de que hagan eso no será considerado para la corrección, pero sí como
concepto. En caso de que haya problemas con lo que le hayan querido agregar (Por
ejemplo, una librería gráfica, de sonido, etc.) tendrán prioridad los que tengan problemas
con la consigna original.

¡LOS MÉTODOS NO DEBEN RECIBIR NI ESCRIBIR EN CONSOLA! (Salvo método
imprimir y si se aclara específicamente).
Genere el main y utilice todos sus métodos para verificar su funcionamiento creando todas
como objetos dinámicos (Recuerde liberar la memoria al creer necesario)
