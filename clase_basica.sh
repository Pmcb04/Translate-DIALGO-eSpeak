echo Inicio de la escena 1
echo "Esto es un ejemplo de dialogo en inglés"
espeak -v en+f1 "Hello, my name is Mary"
espeak -v en-us+m2 "Hi, Mary. I am John"
espeak -v en+f1 "It's nice to meet you"
espeak -v en-us+m2 "Pleased to meet you."
espeak -v en+f1 "How old are you?"
espeak -v en-us+m2 "I'm21years old"
echo Fin de la escena 1
echo Inicio de la escena 2
echo "Esto es un ejercicio para la persona que sigue nuestra clase"
espeak -v es+m1 "Por favor,Alan Turing, repite la frase de cada personaje"
espeak -v en+f1 -s 80 "Hello, my name is Mary"
sleep 1
espeak -v en-us+m2 -a 30 -s 80 "Hi, Mary. I am John"
sleep 1
espeak -v en+f1 -a 200 -s 300 "It's nice to meet you."
sleep 1
espeak -v en-us+m2 -a 30 "Pleased to meet you."
sleep 1
espeak -v es+m1 "Muy bien, Alan Turing. Buen trabajo. Te mereces un 10"
echo Fin de la escena 2
echo Inicio de la escena 3
espeak -v es+m1 "1"
espeak -v en+f1 "1"
espeak -v it+f2 "1"
espeak -v es+m1 "2"
espeak -v en+f1 "2"
espeak -v it+f2 "2"
espeak -v es+m1 "3"
espeak -v en+f1 "3"
espeak -v it+f2 "3"
echo Fin de la escena 3
echo Inicio de la escena 4
echo "Si pones el valor de la bandera inglesoitaliano a 1, las frases se dirán en inglés. "
echo "Si le pones otro valor distinto, se dirán en italiano"
espeak -v es+m1 -s 80 "Escucha la siguiente presentación en inglés"
echo "Escucha atentamente"
espeak -v en+f1 "Hello, my name is Mary"
espeak -v en-us+m2 "Hi, Mary. I am John"
echo Fin de la escena 4
