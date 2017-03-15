ce programme  est correct


 L'arbre de syntaxe astraite: 
Mp Af X1 X2 

Le code C3A: 
ET1       :Sk    :          :          :X2        
ET0       :Af    :X1        :X2        :
ET2       :St    :          :          :


Le code Y86: 
                  .pos      0         #debut zone code 
INIT      :irmovl Data,     %edx      #adresse de la zone de donnees
           irmovl 256,      %eax      #espace pile
           addl   %edx,     %eax                
           rrmovl %eax,     %esp      #init pile 
           rrmovl %eax,     %ebp                
ET1       :nop                        #trad Sk                         X2        
ET0       :mrmovl 4(%edx),  %eax      #trad Af     X1        X2         
           rmmovl %eax,     8(%edx)             
ET2       :halt                       #trad St                          
MUL       :nop                        #ssprog mult:M[M[%edx]]:=X*Y
           mrmovl 4(%esp),  %eax      #A := X   
           mrmovl 8(%esp),  %ebx      # B:= Y   
           andl   %eax,     %eax      # si A==0 return 0
           je     END                           
SIGN      :nop                        #si A <= 0 alors (X:= -A,Y:= -B)
           jg     MULPLUS             #cas ou A > 0
           irmovl 0,        %ecx                
           subl   %eax,     %ecx                
           rrmovl %ecx,     %eax                
           rmmovl %eax,     4(%esp)   #X := -A  
           irmovl 0,        %ecx                
           subl   %ebx,     %ecx                
           rrmovl %ecx,     %ebx                
           rmmovl %ebx,     8(%esp)   #Y := -B  
MULPLUS   :nop                        #ssprog X>0->M[M[%edx]]:=X*Y
           mrmovl 4(%esp),  %eax      #A := X   
           andl   %eax,     %eax      # si X==0 return 0
           je     END                           
           irmovl 1,        %esi      # A:=A-1  
           subl   %esi,     %eax                
           mrmovl 8(%esp),  %ebx      # B:= Y   
           pushl  %ebx                # empiler B, puis A
           pushl  %eax                          
           call   MULPLUS             # M[%edx]:= A * B=(X-1) * Y
           popl   %eax                # depiler A puis B
           popl   %eax                          
           mrmovl 0(%edx),  %eax      # M[%edx]:= M[%edx] + Y
           mrmovl 8(%esp),  %ebx                
           addl   %ebx,     %eax                
           rmmovl %eax,     0(%edx)   #end MUL(X<>0) ret(Z)
           ret                                  
END       :irmovl 0,        %eax      #end MUL(X==0) ret(Z)
           rmmovl %eax,     0(%edx)             
           ret                                  
                  .align    8         #debut zone donnees
Data      :                                     
