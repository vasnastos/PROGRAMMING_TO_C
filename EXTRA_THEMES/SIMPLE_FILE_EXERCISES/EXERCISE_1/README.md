<html>
<body>
<h2 style="text-align:center; font-family:calibri;">ΑΡΧΕΙΑ ΑΣΚΗΣΗ 1</h2>
<h3 style="text-align:center; font-family:calibri;">ΣΥΝΤΑΚΤΗΣ ΝΑΣΤΟΣ ΒΑΣΙΛΕΙΟΣ</h3>
<h4 style="text-align:center; font-family:calibri;">26/06/2020</h4>
<br>
<ul>
<li><p style="text-align:center; font-family:calibri;">Να κατασκευαστεί πρόγραμμα το οποίο θα διαβάζει από ένα αρχείο,το μέγεθος του οποίου είναι άγνωστο,δεκαδικούς αριθμούς και θα εμφανίζει πόσες φορες υπάρχει το μέγιστο στοιχείο του αρχείου,την θέση,θέσεις που υπάρχεί το στοιχείο αυτό,καθώς και πόσα στοιχεία του αρχείου είναι μεγαλύτερα από ένα όρισμα που θα δέχεται από την γραμμή εντολών και την ρίζα του αθροίσματος των αριθμών.Επίσης το όνομα του αρχείου να δίνεται σαν όρισμα από την γραμμή εντολών.</p></li>
<br>
<li><p style="text-align:center; font-family:calibri;">command line arguments-->int main(int argc,char **argv)</p>
<ol>
<li><p style="text-align:center; font-family:calibri;">argc-->counter,πραγματοποιεί καταμέτρηση των ορισμάτων που θα δώσουμε από την γραμμή εντολών.</p></li>
<li><p style="text-align:center; font-family:calibri;">argv-->Πίνακας χαρακτήρων που αποθηκεύει τα ορίσματα που δέχεται από την γραμμή εντολών.</p></li>
<li><p style="text-align:center; font-family:calibri;">Π.Χ:Run_PROGRAM-->a.exe 3.14 abb <br> argc=3 <br> argv[0]="a.exe"-argv[1]="3.14"-argv[2]="abb"</p></li>
</ol>
<li>ΜΕΤΑΓΛΩΤΤΙΣΗ::gcc exercise1.c -o ex1</li>
<br>
<li>EKΤΕΛΕΣΗ::ex1 6.89 numbers.txt</li>
</ul> 
</body>
</html>