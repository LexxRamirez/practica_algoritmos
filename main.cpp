#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
//Mi primer archivo subido
void init(void)
{
GLfloat punto_luz[]={0.0,200.0,200.0,0.0};
GLfloat luz_ambiente[]={1,1,1};
// Activamos la fuente de luz
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0); //Activamos las luces en 0
glDepthFunc(GL_LESS); //comparación de profundidad
glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luz_ambiente);
glLightfv(GL_LIGHT0,GL_POSITION,punto_luz);
//glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
}
void reshape(int w, int h)
{
glViewport(0, 0, (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
glLoadIdentity();
// Usamos proyeccion ortogonal
glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
glLoadIdentity();
}void display(void)
{
// Propiedades del material
GLfloat mat_ambient[] = { 0.329412,0.223529,0.0274};
GLfloat mat_diffuse[] = { 0.780392,0.568627,0.113725};
GLfloat mat_specular[] = { 0.992157,0.941176,0.807843};
GLfloat mat_shine[]= {27.8974};
// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode( GL_MODELVIEW_MATRIX );
glLoadIdentity();
// Rotacion de 25 grados en torno al eje x
glRotated(25.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
glRotated(-30.0, 0.0, 1.0, 0.0);
// Dibujamos una "Tetera" y le aplico el material
glPushMatrix();
//setMaterial
glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shine);
//glMaterialfv(GL_FRONT, GL_SHININESS, shine);
glutSolidSphere(125,50,50);
glFlush();
}int main(int argc, char **argv)
{
// Inicializo OpenGL
glutInit(&argc, argv);
// Activamos buffer simple y colores del tipo RGB
glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
glutInitWindowSize (800, 600);
// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
glutInitWindowPosition (0, 0);
// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
glutCreateWindow ("Tetera con materiales");
// Inicializamos el sistema
init();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}
