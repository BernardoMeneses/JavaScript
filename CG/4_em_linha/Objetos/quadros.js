// quadros.js
import * as THREE from 'https://unpkg.com/three@0.126/build/three.module.js';

export function addQuadrosToWall(wall, imageUrls, positions) {
    const frameWidth = 10;
    const frameHeight = 10;
    const frameDepth = 0.5;
    const loader = new THREE.TextureLoader();

    positions.forEach((pos, index) => {
        const frameGeometry = new THREE.BoxGeometry(frameWidth, frameHeight, frameDepth);
        const frameMaterial = new THREE.MeshPhongMaterial({ color: 0x8B4513 });
        const frame = new THREE.Mesh(frameGeometry, frameMaterial);

        const imageUrl = imageUrls[index % imageUrls.length];
        loader.load(imageUrl, (texture) => {
            const pictureGeometry = new THREE.PlaneGeometry(frameWidth - 1, frameHeight - 1);
            const pictureMaterial = new THREE.MeshBasicMaterial({ map: texture });
            const picture = new THREE.Mesh(pictureGeometry, pictureMaterial);

            picture.position.set(0, 0, frameDepth / 2 + 0.01); // Ajuste a posição para garantir que a imagem fique na frente da moldura
            picture.rotation.y = 2 * Math.PI; // Rotaciona a imagem 180 graus para ficar visível do lado certo

            // Crie um grupo para conter tanto a moldura quanto a imagem
            const quadroGroup = new THREE.Group();
            quadroGroup.add(frame);
            quadroGroup.add(picture);
            quadroGroup.position.set(pos.x, pos.y, pos.z);
            quadroGroup.rotation.y = Math.PI

            wall.add(quadroGroup);
        });
    });
}




