import torch
import math

def attention(Q, K, V, dropout = None):
    d_k = Q.size(-1)
    scores = torch.matmul(Q, K.transpose(-2, -1)) / math.sqrt(d_k)
    attention_weights = scores.softmax(dim = -1)
    if dropout is not None:
        attention_weights = dropout(attention_weights)
    output = torch.matmul(attention_weights, V)
    return output, attention_weights

if __name__ == "__main__":
    batch_size, seq_len, d_k = 2, 4, 8
    
    Q = torch.randn(batch_size, seq_len, d_k)
    K = torch.randn(batch_size, seq_len, d_k) 
    V = torch.randn(batch_size, seq_len, d_k)
    output, attn_weights = attention(Q, K, V)
    
    print("Q shape:", Q.shape)
    print("K shape:", K.shape)
    print("V shape:", V.shape)
    print("Output shape:", output.shape)
    print("Attention Weights:\n", attn_weights)