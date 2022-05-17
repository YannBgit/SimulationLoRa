f_size = 0.003
cex_size = 0.5
pch_id = 20
columns = c("K", "T", "P_col1", "P_col2", "P_col3", "P_col4", "P_col5", "P_col6", "P_col7", "T_em1", "T_em2")

# 7 courbes de probabilités de collision dans les états ej en fonction du temps de la simulation
# + intervalle de confiance à 90% de probabilités de collisions dans l'état e2 (50 simulations).
plot_7_courbes_inter <- function(name)
{
	data = read.table(name)
    colnames(data) = columns

    plot(lowess(data$T, data$P_col1, f = f_size),
         type = "l",
         ylim = c(0, 0.2), 
         pch = pch_id,
         cex = cex_size,
         xlab = "Temps de la simulation T",
         ylab = "Probabilité de collision moyenne",
         col = "blue",
         main = "Probabilité de collision moyenne\nen fonction du temps de la simulation, K fixé à 5")
    lines(lowess(data$T, data$P_col2, f = f_size), col = "green")
    lines(lowess(data$T, data$P_col3, f = f_size), col = "red")
    lines(lowess(data$T, data$P_col4, f = f_size), col = "coral3")
    lines(lowess(data$T, data$P_col5, f = f_size), col = "cyan4")
    lines(lowess(data$T, data$P_col6, f = f_size), col = "darkolivegreen4")
    lines(lowess(data$T, data$P_col7, f = f_size), col = "goldenrod")

    datalowe2 = data$P_col2 * 0.9
    datahighe2 = data$P_col2 * 1.1

    lines(lowess(data$T, datalowe2, f = 0.3), col = "black")
    lines(lowess(data$T, datahighe2, f = 0.3), col = "black")

    legend("topright", legend = paste("Etat", c("e1", "e2", "e3", "e4", "e5", "e6", "e7")),
    lty = "solid", col = c("blue", "green", "red", "coral3", "cyan4", "darkolivegreen4", "goldenrod"))

	# AJOUTER INTERVALLE DE CONFIANCE A 90% DE P_COL2
}

# Tracer deux histogrammes du temps d'émission observé. Le premier concerne l'état e1, le deuxième
# l'état e2. Indiquer la moyenne du temps observé dans chaque histogramme.
plot_histogrammes_TE <- function(name)
{
	data = read.table(name)
    colnames(data) = columns

    datae1 = data[data$T_em1 != -1,]
    datae2 = data[data$T_em2 != -1,]

	hist(datae1$T_em1,
    xlab = "Temps d'émission dans e1",
    col = "lightblue",
    main = "Fréquence du temps d'émission par plage dans e1\nK fixé à 5 sur 100 simulations")
	abline(v = mean(datae1$T_em1), f = f_size, col = "black")
    legend("topright", legend = "Moyenne du temps\nd'émission", lty = "solid", col = "black")

    hist(datae2$T_em2,
    xlab = "Temps d'émission dans e2",
    col = "lightblue",
    main = "Fréquence du temps d'émission par plage dans e2\nK fixé à 5 sur 100 simulations")
	abline(v = mean(datae2$T_em2), f = f_size, col = "black")
    legend("topright", legend = "Moyenne du temps\nd'émission", lty = "solid", col = "black")
}

# Courbe de la probabilité de collision moyenne sur les 7 états d'émission en fonction du
# nombre de capteurs dans le réseau (de 1 à 100).
plot_P_collision_moyenne <- function(name)
{
	data = read.table(name)
    colnames(data) = columns

    datamean = (data$P_col1 + data$P_col2 + data$P_col3 + data$P_col4 + data$P_col5 + data$P_col6 + data$P_col7)/7

    plot(data$K, datamean, 
         pch = pch_id,
         cex = cex_size,
         xlab = "Nombre de capteurs K",
         ylab = "Probabilité de collision moyenne",
         col = "blue",
         main = "Probabilité de collision moyenne\nen fonction du nombre de capteurs")
	lines(lowess(data$K, datamean, f = 0.3), col = "blue")
    abline(h = 0.7, col = "black")
    legend("bottomright", legend = "Probabilité de\ncollision de 70%", lty = "solid", col = "black")
}

plot_7_courbes_inter("lora1.data")
plot_histogrammes_TE("lora1.data")
plot_P_collision_moyenne("lora2.data")