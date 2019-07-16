import numpy as np

class NN(object):
    def __init__(self, input_data, epoch_count):
        pass

    @classmethod
    def activation_func(x):
        '''
            x - it's the output of every neuron in layer
            output_of_neuron = input_of_neuron * weight_of_neuron
        '''
        # there are 2 activation functions
        # you can choose wich one to use by your own
        def sigmoid(value):
            return 1 / 1 + np.exp(-value)

        def htan(value):
            # hyperbolic tangent function
            return np.exp(2 * value) - 1 / np.exp(2 * value) + 1

        # in current NN we are using sigmoid activation function
        return sigmoid(float(x))
