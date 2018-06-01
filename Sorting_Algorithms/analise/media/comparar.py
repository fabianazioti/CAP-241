import numpy as np
import matplotlib.pyplot as plt


tam = np.array([19200, 38400, 76800, 153600, 307200, 614400])

qui = np.array([19200, 38400, 76800, 153600])

#insert_sort_cre = np.loadtxt('insert_sort_cre_media.txt')
#insert_sort_de = np.loadtxt('insert_sort_de_media.txt')
#insert_sort_rand = np.loadtxt('insert_sort_rand_media.txt')

select_sort_cre = np.loadtxt('select_sort_cre_media.txt')
select_sort_de = np.loadtxt('select_sort_de_media.txt')
select_sort_rand = np.loadtxt('select_sort_rand_media.txt')

merge_sort_cre = np.loadtxt('merge_sort_cre_media.txt')
merge_sort_de = np.loadtxt('merge_sort_de_media.txt')
merge_sort_rand = np.loadtxt('merge_sort_rand_media.txt')

heapsort_sort_cre = np.loadtxt('heapsort_sort_cre_media.txt')
heapsort_sort_de = np.loadtxt('heapsort_sort_de_media.txt')
heapsort_sort_rand = np.loadtxt('heapsort_sort_rand_media.txt')

quick_sort_cre = np.loadtxt('quick_sort_cre_media.txt')
quick_sort_de = np.loadtxt('quick_sort_de_media.txt')
quick_sort_rand = np.loadtxt('quick_sort_rand_media.txt')


stlsort_rand = np.loadtxt('stlsort_rand.txt')
stlsort_de = np.loadtxt('stlsort_de.txt')
stlsort_cre = np.loadtxt('stlsort_cre.txt')

stlstable_sort_rand = np.loadtxt('stlstable_sort_rand.txt')
stlstable_sort_de = np.loadtxt('stlstable_sort_de.txt')
stlstable_sort_cre= np.loadtxt('stlstable_sort_cre.txt')
 
stlsort_heap_sort_rand = np.loadtxt('stlsort_heap_sort_rand.txt')
stlsort_heap_sort_de = np.loadtxt('stlsort_heap_sort_de.txt')
stlsort_heap_sort_cre= np.loadtxt('stlsort_heap_sort_cre.txt')

 
#plt.plot(tam, stlsort_cre, label='STL Sort', marker='h')
#plt.plot(tam, stlstable_sort_cre, label='STL Stable Sort', marker='d')
#plt.plot(tam, stlsort_heap_sort_cre, label='STL Heap Sort', marker='*')

# plt.plot(tam, stlsort_de, label='STL Sort', marker='h')
# plt.plot(tam, stlstable_sort_de, label='STL Stable Sort', marker='d')
# plt.plot(tam, stlsort_heap_sort_de, label='STL Heap Sort', marker='*')

plt.plot(tam, stlsort_rand, label='STL Sort', marker='h')
plt.plot(tam, stlstable_sort_rand, label='STL Stable Sort', marker='d')
plt.plot(tam, stlsort_heap_sort_rand, label='STL Heap Sort', marker='*')



#plt.plot(tam, insert_sort_cre, label='Insertion Sort', marker='s')
#plt.plot(tam, insert_sort_de, label='Insertion Sort', marker='s')
#plt.plot(tam, insert_sort_rand, label='Insertion Sort', marker='s')

#plt.plot(tam, select_sort_cre, label='Selection Sort', marker='o')
#plt.plot(tam, select_sort_de, label='Selection Sort', marker='o')
#plt.plot(tam, select_sort_rand, label='Selection Sort', marker='o')

#plt.plot(tam, merge_sort_cre, label='Merge Sort', marker='x')
#plt.plot(tam, heapsort_sort_cre, label='Heap Sort', marker='p')
#plt.plot(qui, quick_sort_cre, label='Quick Sort', marker='p')

# plt.plot(tam, merge_sort_de, label='Merge Sort', marker='x')
# plt.plot(tam, heapsort_sort_de, label='Heap Sort', marker='p')
# plt.plot(qui, quick_sort_de, label='Quick Sort', marker='p')


plt.plot(tam, merge_sort_rand, label='Merge Sort', marker='x')
plt.plot(tam, heapsort_sort_rand, label='Heap Sort', marker='p')
plt.plot(qui, quick_sort_rand, label='Quick Sort', marker='p')

plt.xlabel('Tamanho vetor')
plt.ylabel('Tempo em milliseconds')

#plt.title("Crescente")
# plt.title("Decrescente")
plt.title("Randomico")

plt.legend(loc = 2)

plt.show()

