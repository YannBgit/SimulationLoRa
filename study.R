f_size = 0.3
cex_size = 0.5
pch_id = 20
columns = c("K", "T", "P_col1", "P_col2", "P_col3", "P_col4", "P_col5", "P_col6", "P_col7", "T_em1", "T_em2")

plot_7_courbes_inter <- function(name)
{
	data = read.table(name)
    colnames(data) = columns

    plot(data$T, data$P_col1, 
         pch = pch_id,
         cex = cex_size,
         xlab = "Temps de la simulation T",
         ylab = "Probabilité de collision moyenne",
         col = "blue",
         main = "Probabilité de collision moyenne\nen fonction du temps de la simulation")
    lines(lowess(data$T, data$P_col1, f = f_size), col = "blue")
	points(data$T, data$P_col2, pch = pch_id, cex = cex_size, col = "green")
    lines(lowess(data$T, data$P_col2, f = f_size), col = "green")
	points(data$T, data$P_col3, pch = pch_id, cex = cex_size, col = "red")
    lines(lowess(data$T, data$P_col3, f = f_size), col = "red")
	points(data$T, data$P_col4, pch = pch_id, cex = cex_size, col = "coral3")
    lines(lowess(data$T, data$P_col4, f = f_size), col = "coral3")
	points(data$T, data$P_col5, pch = pch_id, cex = cex_size, col = "cyan4")
    lines(lowess(data$T, data$P_col5, f = f_size), col = "cyan4")
	points(data$T, data$P_col6, pch = pch_id, cex = cex_size, col = "darkolivegreen4")
    lines(lowess(data$T, data$P_col6, f = f_size), col = "darkolivegreen4")
	points(data$T, data$P_col7, pch = pch_id, cex = cex_size, col = "goldenrod")
    lines(lowess(data$T, data$P_col7, f = f_size), col = "goldenrod")

	# AJOUTER INTERVALLE DE CONFIANCE A 90%  DE P_COL2
}

plot_histogrammes_TE <- function(name)
{
	data = read.table(name)
    colnames(data) = columns

	plot(data$T, data$T_em1,
		 type = "h",
         xlab = "Temps de la simulation T",
         ylab = "Temps d'émission en e1",
         col = "blue",
         main = "Temps d'émission en e1\nen fonction du temps de la simulation")
	abline(h = 1000, f = f_size, col = "black")

	plot(data$T, data$T_em2,
		 type = "h",
         xlab = "Temps de la simulation T",
         ylab = "Temps d'émission en e2",
         col = "blue",
         main = "Temps d'émission en e2\nen fonction du temps de la simulation")
	abline(h = 1000, f = f_size, col = "black")

    # CALCULER LA MOYENNE DU TEMPS OBSERVE DANS CHAQUE HISTOGRAMME
}

plot_P_collision_moyenne <- function(name)
{
	data = read.table(name)
    colnames(data) = columns

    plot(data$K, data$P_col1, 
         pch = pch_id,
         cex = cex_size,
         xlab = "Nombre de capteurs K",
         ylab = "Probabilité de collision moyenne",
         col = "blue",
         main = "Probabilité de collision moyenne\nen fonction du nombre de capteurs")
    lines(lowess(data$K, data$P_col1, f = f_size), col = "blue")

	# UTILISER LA MOYENNE DES P_COL AU LIEU DE P_COL1
}

# 7 courbes de probabilités de collision dans les états ej en fonction du temps de la simulation
# + intervalle de confiance à 90% de probabilités de collisions dans l'état e2 (50 simulations).
plot_7_courbes_inter("lora.data")

# Tracer deux histogrammes du temps d'émission observé. Le premier concerne l'état e1, le deuxième
# l'état e2. Indiquer la moyenne du temps observé dans chaque histogramme.
plot_histogrammes_TE("lora.data")

# Courbe de la probabilité de collision moyenne sur les 7 états d'émission) en fonction du
# nombre de capteurs dans le réseau (de 1 à 100).
plot_P_collision_moyenne("lora.data")