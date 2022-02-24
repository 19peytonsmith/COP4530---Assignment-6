<div id="kl_assignments" class="">
<h3 class="">
<i class="icon-assignment" aria-hidden="true"></i>Module Assignments</h3>
<p><strong>Objectives: </strong>Understand and get familiar with the hash table data structure,<br>along with its application in managing user accounts.</p>
<p><br><strong>Task:</strong> Implement a hash table ADT and other supporting user<br>interfaces; develop a simple password server program.</p>
<p><br><strong>Project Description:</strong><br>This project contains two parts. In the first part of the project, you need to implement<br>a hash table class template named HashTable. In the second part of the project, you<br>will develop a simple password server program using the hash table you developed.</p>
<p>Task 1: Requirements of the HastTable Class Template&nbsp;</p>
<ul>
<li>Your implementation of HashTable must be in the namespace of cop4530.<br>You must provide the template declaration and implementation in two different<br>files:
<ul>
<li>hashtable.h (containing HashTable class template declaration)<br>and hashtable.hpp (containing the implementation of member functions).</li>
<li>You must include hashtable.hpp inside hashtable.h as we have done in<br>the previous projects. The two files <em>hashtable.h</em> and <em>hashtable.hpp</em> will<br>be provided to you, which contain some helpful functions that you will<br>need to use in developing the hash table class template.</li>
</ul>
</li>
<li>You must implement hash table using the technique of chaining with separate<br>lists (separate chaining). That is, the internal data structure of the hash table<br>class template should be a vector of lists. Use existing C++ STL containers for<br>the internal storage (instead of any containers you developed in the previous<br>projects)</li>
</ul>
<p><strong>You must implement at minimum all the interfaces specified below for the</strong><br><strong>HashTable class template.</strong></p>
<ul>
<li>
<strong>Public HashTable interface</strong> (K and V are template parameters (generic data<br>types), which represent the key and value types for a table entry, respectively)</li>
<li>
<strong>HashTable(size_t size = 101):</strong> constructor. Create a hash table, where the size<br>of the vector is set to prime_below(size) (where size is default to 101), where<br>prime_below() is a private member function of the HashTable and provided to<br>you.</li>
<li>
<strong>~HashTable(): </strong>destructor. Delete all elements in hash table.</li>
<li>
<strong>bool contains(const K &amp; k):</strong> check if key k is in the hash table.</li>
<li>
<strong>bool match(const std::pair&lt;K, V&gt; &amp;kv) :</strong> check if key-value pair is in the hash<br>table.</li>
<li>
<strong>bool insert(const std::pair&lt;K, V&gt; &amp; kv): </strong>add the key-value pair kv into the<br>hash table. Don't add if kv is already in the hash table. If the key is the hash<br>table but with a different value, the value should be updated to the new one<br>with kv. Return true if kv is inserted or the value is updated; return false<br>otherwise (i.e., if kv is in the hash table).</li>
<li>
<strong>bool insert (std::pair&lt;K, V&gt; &amp;&amp; kv):</strong> move version of insert.</li>
<li>
<strong>bool remove(const K &amp; k): </strong>delete the key k and the corresponding value if it is<br>in the hash table. Return true if k is deleted, return false otherwise (i.e., if key k<br>is not in the hash table).</li>
<li>
<strong>void clear(): </strong>delete all elements in the hash table</li>
<li>
<strong>bool load(const char *filename):</strong> load the content of the file with name<br>filename into the hash table. In the file, each line contains a single pair of key<br>and value, separated by a white space.</li>
<li>
<strong>void dump():</strong> display all entries in the hash table. If an entry contains multiple<br>key-value pairs, separate them by a semicolon character (:) (see the provided<br>executable for the exact output format).</li>
<li>
<strong>bool write_to_file(const char *filename): </strong>write all elements in the hash table<br>into a file with name filename. Similar to the file format in the load function,<br>each line contains a pair of key-value pair, separated by a white space.</li>
</ul>
<p><strong>Private Helper Functions:</strong>&nbsp;</p>
<ul>
<li>
<strong>void makeEmpty():</strong> delete all elements in the hash table. The public interface clear() will call this function.</li>
<li>
<strong>void rehash():</strong> Rehash function. Called when the number of elements in the hash table is greater than the size of the vector.</li>
<li>
<strong>size_t myhash(const K &amp;k):</strong> return the index of the vector entry where k should be stored. COP4530 Data Structures and Algorithm Analysis</li>
<li>
<strong>unsigned long prime_below (unsigned long) and void setPrimes(vector&amp;): </strong>two helpful functions to determine the proper prime numbers used in setting up the vector size. Whenever you need to set hash table to a new size "sz", call prime_below(sz) to determine the new proper underlying vector size. These two functions have been provided in hashtable.h and hashtable.hpp.</li>
</ul>
<p><em>Make sure to declare as const member functions any for which this is appropriate</em><br><em>You need to write a simple test program to test various functions of hash table. More</em><br><em>details are provided in a later part of this description.</em></p>
<p><em>Task 2: Requirements of the Password Server Class (PassSever)</em></p>
<ul>
<li><em>Name the password server class as PassServer. Its declaration and implementation should be provided in two files, passserver.h and passserver.cpp, respectively.</em></li>
<li><em>PassServer should be implemented as an adaptor class, with the HashTable<br>you developed as the adaptee class. The type for both K and V in HashTable<br>should be string. The key and value will be the username and password,<br>respectively.</em></li>
<li><em>PassServer must store username and encrypted password pairs in the hash<br>table.</em></li>
<li><em>PassServer must at least support the following member functions (again, make<br>sure to declare as const member functions any that are appropriate):</em></li>
</ul>
<p><strong><em>Public Interface:&nbsp;</em></strong></p>
<ol>
<li>PassServer(size_t size = 101): constructor, create a hash table of the<br>specified size. You just need to pass this size parameter to the<br>constructor of the HashTable. Therefore, the real hash table size could<br>be different from the parameter size (because prime_below() will be<br>called in the constructor of the HashTable).</li>
<li>~PassServer(): destructor. You need to decide what you should do based<br>on your design of PassServer (how you develop the adaptor class based<br>on the adaptee HashTable). In essence, we do not want to have memory<br>leak.</li>
<li>bool load(const char *filename): load a password file into the<br>HashTable object. Each line contains a pair of username and an un-encrypted<br>password. Read in the name and encrypt the password and populate the hash table.&nbsp;</li>
<li>bool addUser(std::pair&lt;string, string&gt; &amp; kv): add a new username and<br>password. The password passed in is in plaintext, it should be encrypted<br>before insertion.</li>
<li>bool addUser(std::pair&lt;string, string&gt; &amp;&amp; kv): move version of<br>addUser.</li>
<li>bool removeUser(const string &amp; k): delete an existing user with<br>username k.</li>
<li>bool changePassword(const pair&lt;string, string&gt; &amp;p, const string &amp;<br>newpassword): change an existing user's password. Note that both<br>passwords passed in are in plaintext. They should be encrypted before<br>you interact with the hash table. If the user is not in the hash table,<br>return false. If p.second does not match the current password, return<br>false. Also return false if the new password and the old password are the<br>same (i.e., we cannot update the password).</li>
<li>bool find(const string &amp; user): check if a user exists (if user is in the<br>hash table).</li>
<li>void dump(): show the structure and contents of the HashTable object to<br>the screen. Same format as the dump() function in the HashTable class<br>template.</li>
<li>size_t size(): return the size of the HashTable (the number of<br>username/password pairs in the table).</li>
<li>bool write_to_file(const char *filename): Un-encrypt the password from the data structrure and save the username and password combination into a file. Same format as the write_to_file() function in the HashTable class template.</li>
</ol>
<p><strong>Private Helper Functions:&nbsp;&nbsp;</strong></p>
<ul>
<li>string encrypt(const string &amp; str): encrypt the parameter str and return<br>the encrypted string.</li>
<li>For this project, we will use a modified encryption and and un-encryption algorithm that was modified to be used in this course.&nbsp; The code for this <em>base64.h</em> and <em>base64.cpp.&nbsp;</em>
</li>
<li><em>Sample Call to the encryption and decryption functions.&nbsp; (Notice that we declare the character array using defined typdef BYTE.&nbsp; &nbsp;&nbsp;</em></li>
</ul>
<p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; BYTE charin[MAXSIZE];<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; BYTE charout[MAXSIZE];</p>
<p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cout&lt;&lt;"Read in another string: " &lt;&lt;endl;<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cin &gt;&gt; charin;<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; base64_encode(charin,charout,strlen(charin),1);<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cout &lt;&lt;endl&lt;&lt;charout&lt;&lt;endl;<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; base64_decode(charout,charin,strlen(charout));<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cout &lt;&lt;endl&lt;&lt;charin&lt;&lt;endl;<br><br><em></em></p>
<p><strong>Driver Program:</strong></p>
<p>In addition to developing the HashTable class<br>template and the PassServer class, you need to write a driver<br>program to test your code. Name the driver program <span style="text-decoration: underline;"><em>proj6.cpp.</em></span></p>
<ul>
<li>&nbsp;A partial implementation of proj6.cpp is provided to you, which<br>contains a Menu() function. You must use this function as the<br>standard option menu for user to type input. You may not alter<br>the Menu function.</li>
<li>The driver program must re-prompt the user for the next choice<br>from the menu and exit the program only when the user<br>selection the exit "x" option.</li>
<li>Run the provided executable proj6.x on linprog to see the<br>expected behavior of each of the menu options, and the<br>expected order of inputs. Make sure to test with error cases too,<br>so that you see the appropriate error messages that are printed.</li>
</ul>
<p><strong>Provided Partial code:&nbsp; The following partial code has been provided for you.&nbsp;&nbsp;</strong></p>
<ol>
<li>&nbsp;hashtable.h: partial implementation</li>
<li>&nbsp;hashtable.hpp: partial implementation</li>
<li>proj6.cpp: driver program, partial implementation.</li>
<li>test1: sample test case (which contains the commands that a user<br>will type). You can redirect it to proj6.x as "proj6.x &lt; test1".<br>Results will save in the file "outtest1"</li>
<li>base64.h&nbsp; &nbsp; &nbsp;Definition file for the encryption algorithm.&nbsp; Do not modify these files.&nbsp;</li>
<li>base64.cpp&nbsp; Implementation file for the encryption algorithm&nbsp; do not modify these files.&nbsp;&nbsp;</li>
</ol>
<p><strong>Deliverables:&nbsp; </strong></p>
<p>Your implementation must be entirely contained in the following files, which<br>MUST be named in the same way.</p>
<p>Submit all the files in a tar file via the Canvas system. If you have implemented the<br>extra-points version, please indicate so when you submit your homework.</p>
<p>Your program must compile on linprog.cs.fsu.edu. If you program does not compile<br>on linprog, the grader cannot test your submission. Your executable(s) must be named<br>proj6.x</p>
</div>
</div>
