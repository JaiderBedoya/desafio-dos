s t a t i o n . h  
 # i n c l u d e   " S t a t i o n . h "  
  
 / / C o n s t r u c t o r   m i e m b r o   a   m i e m b r o  
 S t a t i o n : : S t a t i o n ( s t r i n g   n o m b r e _ ,   s t r i n g   c o d i g o _ ,   s t r i n g   g e r e n t e _ ,   s t r i n g   r e g i o n _ ,   s t r i n g   u b i c a c i o n _ ,   u n s i g n e d   s h o r t   i n t   n u m e r o S u r t i d o r e s _ ) :   n o m b r e ( n o m b r e _ ) ,   c o d i g o ( c o d i g o _ ) ,   g e r e n t e ( g e r e n t e _ ) ,   r e g i o n ( r e g i o n _ ) ,   u b i c a c i o n ( u b i c a c i o n _ ) ,   n u m e r o S u r t i d o r e s ( n u m e r o S u r t i d o r e s _ ) { }  
 / / D e s t r u c t o r  
 S t a t i o n : : ~ S t a t i o n ( ) { } ;  
 / / g e t t e r s  
 s t r i n g   S t a t i o n : : g e t N o m b r e ( )   c o n s t   {  
         r e t u r n   n o m b r e ;  
 }  
 s t r i n g   S t a t i o n : : g e t C o d i g o ( )   c o n s t   {  
         r e t u r n   c o d i g o ;  
 }  
 s t r i n g   S t a t i o n : : g e t G e r e n t e ( )   c o n s t   {  
         r e t u r n   g e r e n t e ;  
 }  
 s t r i n g   S t a t i o n : : g e t R e g i o n ( )   c o n s t   {  
         r e t u r n   r e g i o n ;  
 }  
 s t r i n g   S t a t i o n : : g e t U b i c a c i o n ( )   c o n s t   {  
         r e t u r n   u b i c a c i o n ;  
 }  
 u n s i g n e d   s h o r t   i n t   S t a t i o n : : g e t N u m e r o S u r t i d o r e s ( )   c o n s t   {  
         r e t u r n   n u m e r o S u r t i d o r e s ;  
 }  
 u n s i g n e d   s h o r t   i n t   S t a t i o n : : g e t S u r t i d o r e s A c t i v o s ( )   c o n s t   {  
         r e t u r n   s u r t i d o r e s A c t i v o s  
 }  
 u n s i g n e d   s h o r t   i n t   S t a t i o n : : g e t C o m b u s t i b l e R e g u l a r ( )   c o n s t {  
         r e t u r n   t a n q u e [ 0 ] ;  
 }  
 u n s i g n e d   s h o r t   i n t   S t a t i o n : : g e t C o m b u s t i b l e P r e m i u m ( )   c o n s t {  
         r e t u r n   t a n q u e [ 1 ] ;  
 }  
 u n s i g n e d   s h o r t   i n t   S t a t i o n : : g e t C o m b u s t i b l e E c o E x t r a ( )   c o n s t {  
         r e t u r n   t a n q u e [ 2 ] ;  
 }  
  
 / / s e t t e r s  
 v o i d   S t a t i o n : : s e t N o m b r e ( s t r i n g   n u e v o N o m b r e ) {  
         n o m b r e   =   n u e v o N o m b r e ;  
 }  
 v o i d   S t a t i o n : : s e t G e r e n t e ( s t r i n g   n u e v o G e r e n t e ) {  
         g e r e n t e   =   n u e v o G e r e n t e ;  
 }  
 v o i d   S t a t i o n : : s e t R e g i o n ( s t r i n g   n u e v a R e g i o n ) {  
         r e g i o n   =   n u e v a R e g i o n ;  
 }  
 v o i d   S t a t i o n : : s e t U b i c a c i o n ( s t r i n g   n u e v a U b i c a c i o n ) {  
         u b i c a c i o n   =   n u e v a U b i c a c i o n ;  
 }  
 v o i d   S t a t i o n : : s e t N u m e r o S u r t i d o r e s ( u n s i g n e d   s h o r t   i n t   n u e v o N u m e r o S u r t i d o r e s ) {  
         n u m e r o S u r t i d o r e s   =   n u e v o N u m e r o S u r t i d o r e s ;  
 }  
 v o i d   S t a t i o n : : s e t S u r t i d o r e s A c t i v o s ( u n s i g n e d   s h o r t   i n t   n u m e r o S u r t i d o r e s A c t i v o s ) {  
         n u m e r o S u r t i d o r e s A c t i v o s   =   n u m e r o S u r t i d o r e s A c t i v o s ;  
 }  
 