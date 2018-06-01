import numpy as np
import matplotlib.pyplot as plt


tam = np.array([19200, 38400, 76800, 153600, 307200, 614400])

#tam = np.array([19200, 38400, 76800, 153600])

heap_cre = np.loadtxt('insert_sort_cre_media.txt')

heap_de = np.loadtxt('insert_sort_de_media.txt')

heap_rand = np.loadtxt('insert_sort_rand_media.txt')

plt.plot(tam, heap_cre, label='Crescente', marker='s')
plt.plot(tam, heap_de, label='Decrescente', marker='s')
plt.plot(tam, heap_rand, label='Aleatorio', marker='s')

plt.xlabel('Tamanho vetor')
plt.ylabel('Tempo em milliseconds')

plt.title("Insertion Sort")

plt.legend()

plt.show()

