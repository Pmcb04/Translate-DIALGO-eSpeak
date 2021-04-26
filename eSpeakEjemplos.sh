echo Ejemplos con algunas opciones del software de síntesis de voz eSpeak
espeak -v es+f1 "Hola. Esto es un ejemplo de síntesis de voz de eSpeak"
echo Estas son las opciones de idiomas y voces disponibles
espeak --voices
sleep .5s
echo Ejemplos de voces, idiomas y lectura de números
espeak -v es+f1 "Mujer hablante de castellano diciendo algo escrito en castellano"
espeak -v es+m1 "Hombre hablante de castellano diciendo algo escrito en castellano"
espeak -v en+f2 "English woman reading something written in English"
espeak -v en+m2 "English man reading something written in English"
espeak -v es+m2 "Spanish man reading something written in English"
espeak -v es+whisper "Esto es un hombre susurrando"
espeak -v es+whisperf "Y esto es una mujer susurrando"
espeak -v es "He sacado un 9.75. ¿Y tú?"
sleep .5s
echo Ejemplos con distinto volumen
espeak -v es+m2 "Texto con volumen normal"
espeak -a 200 -v es+m2 "Texto con volumen al máximo"
echo Ejemplos a distinta velocidad y con distintas pausas
espeak -v es+m3 "Texto leído a la velocidad por omisión de 175 palabras por minuto"
espeak -v es+m3 -s 100 "Texto leído a una velocidad de 100 palabras por minuto"
espeak -v es+m3 -s 400 "Texto leído a una velocidad de 400 palabras por minuto"
espeak -v es+m3 -g 30 "Texto a velocidad normal, con una pausa de 300 milisegundos entre palabras"
echo Ejemplos con distinto tono de voz
espeak -v es -p 0 "Texto con el tono de voz  más grave"
espeak -v es -p 99 "Texto con el tono de voz más agudo"

echo Fin
