#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#define TAMANHO_JANELA 500

float gX = 0.0;
float gY = 0.0;
int keyStatus[256];

void idle(void){
   if(keyStatus[(int)('a')]){
      gX= gX-0.1;
      printf("oi1\n");
   }
   if(keyStatus[(int)('s')] == 1){
      gY = gY-0.1;
      printf("oi2\n");

   }
   if(keyStatus[(int)('d')] == 1){
     gX= gX+0.1;
     printf("oi3\n");
   
   }
    if(keyStatus[(int)('w')] == 1){
      gY = gY+0.1;
      printf("oi4\n");
      
   }
   glutPostRedisplay();
}

void keyUp(unsigned char key, int x, int y){
   keyStatus[(int)(key)] = 0;
}

void keyPress(unsigned char key, int x, int y){
   keyStatus[(int)(key)] =1;
}

/*void keyPress(unsigned char key, int x, int y){
   if(key == 'a'){
      gX= gX-0.01;
   }
   if(key == 's'){
      gY = gY-0.01;
   }
   if(key == 'd'){
      gX = gX+0.01;
   }
   if(key == 'w'){
      gY = gY+0.01;    
   }
   
   glutPostRedisplay();
}*/

void display(void){
   /* Limpar todos os pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   /* Define cor dos vértices com os valores R, G e B variando de 0.0 a 1.0 */
   glColor3f (1.0, 1.0, 1.0);
   /* Desenhar um polígono branco (retângulo) */
   glBegin(GL_POLYGON);

      glVertex3f (0.25+gX, 0.25+gY, 0.0); // inf esq
      glVertex3f (0.75+gX, 0.25+gY, 0.0); // sup esq
      glVertex3f (0.75+gX, 0.75+gY, 0.0); // sup dir
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
   init();
   glutDisplayFunc(display); 
   glutKeyboardFunc(keyPress);
   glutKeyboardUpFunc(keyUp);
   idle();
      
   glutMainLoop();

   return 0;
}
