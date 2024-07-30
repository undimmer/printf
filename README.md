<h1 align="center"><img src="BannerPrintf.gif" alt="Profile banner"/></h1>

En el proyecto ft_printf se nos presenta el trabajo de realizar la función Printf de la biblioteca de , en la cuál se aprenderá el uso de cadenas de carácteres y la implementación de funciones variáticas. 
Una vez realizada su corrección y validación, podremos usar esta función para el resto de proyectos del Cursus. 


<table>
    <thead>
        <tr>
            <th colspan="4" id="original-functions" margin="30"><h3>Makefile y Header</h3></th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td width="10%"><a href="./Makefile"><code>Makefile</code></a></td>
            <td width="40%">Archivo de instrucciones para compilar y construir la biblioteca libft.</td>
            <td width="10%"><a href="./ft_printf.h"><code>ft_printf.h</code></a></td>
            <td width="40%">El header Archivo incluye las descripciones anticipadas de las funciones y las definiciones esenciales.</td>
        </tr>
    </tbody>
</table>

## Lista de funciones utilizadas de proyecto libft

|      Funciones de libft         |      Explicación                           |
| :-----------------------------: | :-----------------------------:            | 
| ft_strlen                       | Devuelve la longitud de la cadena          |
| ft_pf_putchar                   | Imprime un caracter y aumenta el resultado |
| ft_pf_putstr                    | Imprime una cadena y aumenta el resultado por la longitud de la cadena |
| ft_pf_pointer                   | Convierte un puntero a una cadena hexadecimal y la imprime |               

## Lista de macros utilizadas

|     Macros                      |     Explicación                                          |
| :-----------------------------: | :-----------------------------:                          | 
| write                           | Los bytes indicados del bufger serán escritos en el file |
| va_start                        | Permite acceso a los argumentos de la función variada    |
| va_arg                          | Accede al argumento de la función variada                |
| va_copy                         | Hace una copia de los argumentos de la función variática |               
