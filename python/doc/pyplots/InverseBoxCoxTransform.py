import openturns as ot
from matplotlib import pyplot as plt
from openturns.viewer import View

# Create a Box Cox transformation
myLambda = ot.NumericalPoint([0.0, 0.1, 1.0, 1.5])

graph = ot.Graph()
for i in range(myLambda.getDimension()):
    myBoxCox = ot.InverseBoxCoxTransform(myLambda[i])
    graph.add(myBoxCox.draw(0.1, 2.1))

graph.setColors(['red', 'blue', 'black', 'green'])
graph.setLegends(['lambda = ' + str(lam) for lam in myLambda])


graph.setLegendPosition("topleft")

fig = plt.figure(figsize=(8, 4))
plt.suptitle("Inverse Box Cox transformations")
axis = fig.add_subplot(111)
axis.set_xlim(auto=True)

View(graph, figure=fig, axes=[axis], add_legend=True)
