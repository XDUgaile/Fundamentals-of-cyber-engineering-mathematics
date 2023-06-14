import numpy as np
from scipy.linalg import svd
from PIL import Image
import matplotlib.pyplot as plt

def embed_text_in_image(img, text, k=50):
    img_gray = img.convert('L')
    img_array = np.array(img_gray, dtype=np.float64)

    U, s, Vh = svd(img_array)

    # Embed the text in the k-th singular vector
    Vh[k, :len(text)] = [ord(c) for c in text]

    # Reconstruct the image
    new_img_array = np.dot(U * s, Vh)
    new_img_array = np.clip(new_img_array, 0, 255)
    new_img = Image.fromarray(new_img_array.astype(np.uint8))

    return new_img

def extract_text_from_image(img, k=50, text_len=100):
    img_gray = img.convert('L')
    img_array = np.array(img_gray, dtype=np.float64)

    U, s, Vh = svd(img_array)

    # Extract the text from the k-th singular vector
    text = ''.join(chr(int(round(v))) for v in Vh[k, :text_len])

    return text

def main():
    # Load the image
    img = Image.open(r'F:\s.jpg')

    # Embed the question in the image
    question = "What is the capital of China?"
    img_with_question = embed_text_in_image(img, question)

    # Save and display the image with the question
    img_with_question.save('image_with_question.jpg')
    plt.imshow(img_with_question)
    plt.show()

    # Extract the question from the image
    extracted_question = extract_text_from_image(img_with_question)
    print(f"Extracted question: {extracted_question}")

    # Answer the question and embed the answer in the image
    answer = "Beijing"
    img_with_answer = embed_text_in_image(img_with_question, answer)

    # Save and display the image with the answer
    img_with_answer.save('image_with_answer.jpg')
    plt.imshow(img_with_answer)
    plt.show()

    # Extract the answer from the image
    extracted_answer = extract_text_from_image(img_with_answer)
    print(f"Extracted answer: {extracted_answer}")

if __name__ == "__main__":
    main()
