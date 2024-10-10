# i f n d e f   S T A T I O N _ H  
 # d e f i n e   S T A T I O N _ H  
 # i n c l u d e   < s t r i n g >  
 # i n c l u d e   < i o s t r e a m >  
 # i n c l u d e   < f s t r e a m >  
 # i n c l u d e   < r a n d o m >  
 u s i n g   n a m e s p a c e   s t d ;  
  
 c l a s s   S t a t i o n   {  
 p r i v a t e :  
         s t r i n g   n o m b r e ;  
         s t r i n g   c o d i g o ;  
         s t r i n g   g e r e n t e ;  
         s t r i n g   r e g i o n ;  
         s t r i n g   u b i c a c i o n ;  
         u n s i g n e d   s h o r t   i n t   t a n q u e [ 3 ]   =   { 0 , 0 , 0 } ;  
         u n s i g n e d   s h o r t   i n t   n u m e r o S u r t i d o r e s ;  
         u n s i g n e d   s h o r t   i n t   s u r t i d o r e s A c t i v o s ;  
  
 p u b l i c :  
  
         S t a t i o n ( s t r i n g   n o m b r e ,   s t r i n g   c o d i g o ,   s t r i n g   g e r e n t e ,   s t r i n g   r e g i o n ,   s t r i n g   u b i c a c i o n ,   u n s i g n e d   s h o r t   i n t   n u m e r o S u r t i d o r e s ,   u n s i g n e d   s h o r t   i n t   s u r t i d o r e s A c t i v o s ) ;  
         ~ S t a t i o n ( ) ;  
  
         s t r i n g   g e t N o m b r e ( )   c o n s t ;  
         s t r i n g   g e t C o d i g o ( )   c o n s t ;  
         s t r i n g   g e t G e r e n t e ( )   c o n s t ;  
         s t r i n g   g e t R e g i o n ( )   c o n s t ;  
         s t r i n g   g e t U b i c a c i o n ( )   c o n s t ;  
         u n s i g n e d   s h o r t   i n t   g e t N u m e r o S u r t i d o r e s ( )   c o n s t ;  
         u n s i g n e d   s h o r t   i n t   g e t S u r t i d o r e s A c t i v o s ( )   c o n s t ;  
         u n s i g n e d   s h o r t   i n t   g e t C o m b u s t i b l e R e g u l a r ( )   c o n s t ;  
         u n s i g n e d   s h o r t   i n t   g e t C o m b u s t i b l e P r e m i u m ( )   c o n s t ;  
         u n s i g n e d   s h o r t   i n t   g e t C o m b u s t i b l e E c o E x t r a ( )   c o n s t ;  
  
         v o i d   s e t N o m b r e ( s t r i n g   n u e v o N o m b r e ) ;  
         v o i d   s e t G e r e n t e ( s t r i n g   n u e v o G e r e n t e ) ;  
         v o i d   s e t R e g i o n ( s t r i n g   n u e v a R e g i o n ) ;  
         v o i d   s e t U b i c a c i o n ( s t r i n g   n u e v a U b i c a c i o n ) ;  
         v o i d   s e t N u m e r o S u r t i d o r e s ( u n s i g n e d   s h o r t   i n t   n u e v o N u m e r o S u r t i d o r e s ) ;  
         v o i d   s e t S u r t i d o r e s A c t i v o s ( u n s i g n e d   s h o r t   i n t   n u m e r o S u r t i d o r e s A c t i v o s ) ;  
  
         v o i d   a g r e g a r S u r t i d o r ( s t r i n g   c o d i g o ) ;  
         v o i d   e l i m i n a r S u r t i d o r ( s t r i n g   c o d i g o ,   s t r i n g   m o d e l o ) ;  
         v o i d   a c t i v a r S u r t i d o r ( b o o l   a c t i v a c i o n ,   s t r i n g   m o d e l o ) ;  
         v o i d   c o n s u l t a r H i s t o r i c o S u r t i d o r ( s t r i n g   c o d i g o ,   s t r i n g   m o d e l o ) ;  
         v o i d   a s i g n a r L i t r o s A l T a n q u e ( ) ;  
  
 } ;  
  
 # e n d i f  
 