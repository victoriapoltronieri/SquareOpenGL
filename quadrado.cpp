#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#define TAMANHO_JANELA 500

float gX = 0;
float gY = 0;

void keyPress(unsigned char key, int gX, int gY){
   if(key == 'a'){
      printf("%d\n", gX);
      gX=-150;
      printf("oi\n");
     printf("%d\n", gX);
   }
   if(key == 's'){
      gY = gY - 150;
       printf("oi2\n");
   }
   if(key == 'd'){
      gX = gX + 150;
       printf("oi3\n");
   }
   if(key == 'w'){
      gY = gY + 150;
       printf("oi4\n");
       
   }
   
   glutPostRedisplay();
}

void display(void){
   /* Limpar todos os pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   /* Define cor dos vértices com os valores R, G e B variando de 0.0 a 1.0 */
   glColor3f (1.0, 1.0, 1.0);
   /* Desenhar um polígono branco (retângulo) */
   glBegin(GL_POLYGON);

      glVertex3f (0.25+gX, 0.25+gY, 0.0); // inf esq
      glVertex3f (0.75+gX, 0.25+gY, 0.0); // sup esq
      glVertex3f (0.75+gX, 0.75+gX, 0.0); // sup dir
      glVertex3f (0.25+gX, 0.75+gY, 0.0); // inf dir
   
   glEnd();

   /* Desenhar no frame buffer! */
   glutSwapBuffers(); //Funcao apropriada para janela double buffer
}

void init (void) {
  /* selecionar cor de fundo (preto) */
  glClearColor (0.0, 0.0, 0.0, 0.0);

  /* inicializar sistema de visualizacao */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (TAMANHO_JANELA, TAMANHO_JANELA); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello world");
   init ();
   glutDisplayFunc(display); 
   glutKeyboardFunc(keyPress);
   glutPostRedisplay();
      
   glutMainLoop();

   return 0;
}
