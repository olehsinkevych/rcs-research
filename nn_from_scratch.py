import numpy as np
import math
import matplotlib.pyplot as plt
import logging

class Activation(object):
    @classmethod
    def sigmoid(cls, x):
        return 1 / 1 + math.e ** (-x)

    @classmethod
    def sigmoid_derivative(cls, x):
        return Activation.sigmoid(x) * (1 - Activation.sigmoid(x))

    @classmethod
    def tanh(cls, x):
        return np.tanh(x)

    @classmethod
    def tanh_prime(cls, x):
        return 1 - np.tanh(x) ** 2




# loss function and its derivative
def mse(y_true, y_pred):
    return np.mean(np.power(y_true-y_pred, 2))

def mse_prime(y_true, y_pred):
    return 2*(y_pred-y_true)/y_true.size





class InitialLayer(object):
    def __init__(self, input_size, output_size):
        # inp size - size of inputs neurons , output size - size of output neurons
        try:
            self.weights = np.random.randn(input_size, output_size) / np.sqrt(input_size)
            self.bias    = np.random.randn(1, output_size) + 0.5 # 0.5 - floating value

        except TypeError:
            logging.error(' LOG: ... Input layer and output layer sizes should be more than 0 and not NONE')

    def forward_propagation(self, input_data):
        self.input  = input_data
        self.output = np.dot(self.input, self.weights) + self.bias

        return self.output

    def back_propagation(self, output_error, learning_rate):
        input_error   = np.dot(output_error, self.weights.T)
        weights_error = np.dot(self.input.T, output_error)
        # dBias = output_error

        # update parameters
        self.weights -= learning_rate * weights_error
        self.bias    -= learning_rate * output_error

        return input_error


class ActivationLayer(object):
    def __init__(self, activation_func, prime_activation_func):
        try:
            self.activation       = activation_func
            self.prime_activation = prime_activation_func
            if (self.activation or self.prime_activation) == None:
                raise Exception

        except Exception:
            logging.error('Please input ur activation functions, they should be defined!')

    def forward_propagation(self, input_data):
        self.input  = input_data
        self.output = self.activation(self.input)

        return self.output

    def back_propagation(self, output_error, learning_rate):
        return self.prime_activation(self.input) * output_error

glob_err = []

class NN (object):
    def __init__(self):
        self.layers     = []
        self.cost       = None
        self.cost_prime = None

    def add_layer(self, layer):
        self.layers.append(layer)

    def set_cost_functions(self, cost_func, cost_prime_func):
        self.cost       = cost_func
        self.cost_prime = cost_prime_func

    def predict_values(self, input_data):
        sample_size = len(input_data)
        result = []
        for i in range(sample_size):
            output = input_data[i]
            for layer in self.layers:
                output = layer.forward_propagation(output)
            result.append(output)
        return result

    def train(self, input_train, output_train, epochs, learning_rate):
        # sample dimension first
        sample_size = len(x_train)

        # training loop
        for i in range(epochs):
            err = 0
            for j in range(sample_size):
                # forward propagation
                output = x_train[j]
                for layer in self.layers:
                    output = layer.forward_propagation(output)

                # backward propagation
                error = self.cost_prime(y_train[j], output)
                for layer in reversed(self.layers):
                    error = layer.back_propagation(error, learning_rate)

                err += self.cost(y_train[j], output)

                # backward propagation
                error = self.cost_prime(y_train[j], output)
                for layer in reversed(self.layers):
                    error = layer.back_propagation(error, learning_rate)

                # calculate average error on all samples
            err /= sample_size
            # calculate average error on all samples

            glob_err.append(err)
            print('epoch %d/%d   error=%f' % (i+1, epochs, err))


# year / distance / motor / kpp
x_train = np.array([[[2.05, 0.330]], [[2.19, 0.5]], [[2.14, 0.65]], [[2.09, 0.137]]])
y_train = np.array([[[0.09]], [[0.48]], [[0.15]], [[0.1150]]])

net = NN()
net.add_layer(InitialLayer(2, 3))
net.add_layer(ActivationLayer(Activation.tanh, Activation.tanh_prime))
net.add_layer(InitialLayer(3, 1))
net.add_layer(ActivationLayer(Activation.tanh, Activation.tanh_prime))
# train
net.set_cost_functions(mse, mse_prime)
net.train(x_train, y_train, 5000, learning_rate=0.1)
# test
out = net.predict_values(x_train)
print(out)

trys1 = np.array([[2.13, 0.81]])
trys2 = np.array([[2.03, 0.275]])

myt1 = net.predict_values(trys1)
myt2 = net.predict_values(trys2)
print(myt1)
print(myt2)

plt.plot(range(5000), glob_err)
plt.show()